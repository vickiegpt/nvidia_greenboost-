# GreenBoost v2.4 — Kernel module + CUDA shim build system
# Author: Ferran Duarri
# 3-tier: RTX 5070 12 GB VRAM | 51 GB DDR4 pool | 576 GB NVMe swap = 639 GB

KDIR    := /lib/modules/$(shell uname -r)/build
PWD     := $(shell pwd)
CC      := gcc
SHIM    := libgreenboost_cuda.so
MODULE  := greenboost.ko

# Default parameters — 3-tier pool
PHYS_GB    ?= 12   # T1: RTX 5070 VRAM
VIRT_GB    ?= 51   # T2: DDR4 pool (80% of 64 GB)
RESERVE_GB ?= 12   # T2: safety reserve always kept free
NVME_GB    ?= 576  # T3: NVMe swap total (Samsung 990 Evo Plus)
NVME_POOL  ?= 512  # T3: GreenBoost soft cap on T3 allocations

obj-m += greenboost.o

.PHONY: all module shim clean install uninstall load unload reload status help

all: module shim

module:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

shim: greenboost_cuda_shim.c greenboost_cuda.map
	$(CC) -shared -fPIC -O2 -std=gnu11 -o $(SHIM) greenboost_cuda_shim.c -ldl -lpthread \
		-Wl,--version-script=greenboost_cuda.map
	@echo "[GreenBoost] Built $(SHIM)"

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm -f $(SHIM)

install: all
	$(MAKE) -C $(KDIR) M=$(PWD) modules_install
	depmod -a
	cp $(SHIM) /usr/local/lib/
	ldconfig
	@echo "[GreenBoost] Module and shim installed"
	@echo "[GreenBoost] Load with: sudo modprobe greenboost"
	@echo "[GreenBoost] Run app : LD_PRELOAD=/usr/local/lib/$(SHIM) your_app"

uninstall:
	rmmod greenboost 2>/dev/null || true
	rm -f /lib/modules/$(shell uname -r)/extra/greenboost.ko
	rm -f /usr/local/lib/$(SHIM)
	depmod -a

# Load with default RTX 5070 parameters
load: module
	@if lsmod | grep -q "^greenboost "; then \
		echo "[GreenBoost] Already loaded — reloading..."; \
		sudo rmmod greenboost || true; \
	fi
	sudo insmod $(MODULE) \
		physical_vram_gb=$(PHYS_GB) \
		virtual_vram_gb=$(VIRT_GB)  \
		safety_reserve_gb=$(RESERVE_GB) \
		nvme_swap_gb=$(NVME_GB) \
		nvme_pool_gb=$(NVME_POOL)
	@# Apply udev permissions so ollama (video group) can open /dev/greenboost
	@if [ -f /etc/udev/rules.d/99-greenboost.rules ]; then \
		sudo udevadm trigger --name-match=greenboost 2>/dev/null || true; \
	else \
		sudo chmod 660 /dev/greenboost && sudo chgrp video /dev/greenboost 2>/dev/null || true; \
	fi
	@echo "[GreenBoost] v2.2 loaded — 3-tier pool:"
	@echo "[GreenBoost]   T1 VRAM  : $(PHYS_GB) GB  RTX 5070"
	@echo "[GreenBoost]   T2 DDR4  : $(VIRT_GB) GB  pool"
	@echo "[GreenBoost]   T3 NVMe  : $(NVME_GB) GB  swap"
	@echo "[GreenBoost]   Combined : $$(( $(PHYS_GB) + $(VIRT_GB) + $(NVME_GB) )) GB"
	@echo "[GreenBoost] Pool info: cat /sys/class/greenboost/greenboost/pool_info"

unload:
	sudo rmmod greenboost 2>/dev/null || true
	@echo "[GreenBoost] Unloaded"

reload: unload load

status:
	@echo ""
	@echo "=== GreenBoost v2.2 Status (3-tier pool) ==="
	@echo ""
	@lsmod | grep -E "^greenboost" && echo "  Module: LOADED" || echo "  Module: not loaded"
	@echo ""
	@cat /sys/class/greenboost/greenboost/pool_info 2>/dev/null || echo "  (module not loaded)"
	@echo ""
	@echo "=== NVMe swap (Tier 3) ==="
	@swapon --show 2>/dev/null | sed 's/^/  /' || echo "  (swapon not available)"
	@echo ""
	@echo "=== Recent kernel messages ==="
	@dmesg | grep greenboost | tail -10 | sed 's/^/  /'

help:
	@echo ""
	@echo "  GreenBoost v2.2 — 3-Tier GPU Memory Pool"
	@echo "  Author : Ferran Duarri"
	@echo "  Target : ASUS RTX 5070 12 GB + 64 GB DDR4-3600 + 4 TB NVMe"
	@echo ""
	@echo "  Tier 1  RTX 5070 VRAM   12 GB   ~336 GB/s  [hot layers]"
	@echo "  Tier 2  DDR4 pool       51 GB    ~50 GB/s  [cold layers]"
	@echo "  Tier 3  NVMe swap      576 GB    ~1.8 GB/s  [frozen pages]"
	@echo "          Combined       639 GB"
	@echo ""
	@echo "  BUILD:"
	@echo "    make               — build module (greenboost.ko) + shim ($(SHIM))"
	@echo "    make module        — kernel module only"
	@echo "    make shim          — CUDA shim only"
	@echo "    make clean         — remove all build artifacts"
	@echo ""
	@echo "  LOAD / UNLOAD:"
	@echo "    make load          — insmod with default 3-tier params"
	@echo "    make unload        — rmmod greenboost"
	@echo "    make reload        — unload + load"
	@echo "    make status        — pool info + NVMe swap + recent dmesg"
	@echo ""
	@echo "  PARAMETERS (override on command line):"
	@echo "    PHYS_GB=12         — T1: physical VRAM GB (RTX 5070)"
	@echo "    VIRT_GB=51         — T2: DDR4 pool GB"
	@echo "    RESERVE_GB=12      — T2: system RAM to keep free always"
	@echo "    NVME_GB=576        — T3: NVMe swap total GB"
	@echo "    NVME_POOL=512      — T3: GreenBoost soft cap GB"
	@echo "    Example: make load NVME_GB=576 VIRT_GB=51"
	@echo ""
	@echo "  CUDA SHIM (transparent DDR4/NVMe overflow via NVIDIA UVM):"
	@echo "    LD_PRELOAD=./$(SHIM) your_cuda_app"
	@echo "    GREENBOOST_THRESHOLD_MB=512 LD_PRELOAD=./$(SHIM) your_app"
	@echo "    GREENBOOST_DEBUG=1 LD_PRELOAD=./$(SHIM) your_app"
	@echo ""
	@echo "  MONITORING:"
	@echo "    cat /sys/class/greenboost/greenboost/pool_info   (3-tier)"
	@echo "    cat /sys/class/greenboost/greenboost/active_buffers"
	@echo "    swapon --show                                    (T3 NVMe)"
	@echo "    dmesg | grep greenboost"
	@echo "    make status"
	@echo ""
