#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x367fcc51, "module_layout" },
	{ 0x53cb74, "param_ops_int" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0xdab7d900, "kthread_stop" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xc6e25dc2, "cdev_del" },
	{ 0x7fbb56eb, "class_destroy" },
	{ 0xb86f74c5, "free_cpumask_var" },
	{ 0xd08c9f2e, "set_cpus_allowed_ptr" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x211130c1, "alloc_cpumask_var" },
	{ 0xeae2f6cd, "device_destroy" },
	{ 0x9f52f3a1, "wake_up_process" },
	{ 0x25ec772e, "kthread_create_on_node" },
	{ 0xfbd2f6ab, "device_create_with_groups" },
	{ 0xec8c17d0, "__class_create" },
	{ 0x6bfecf8d, "cdev_add" },
	{ 0xbe15ede5, "cdev_init" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xf185940b, "__mmap_lock_do_trace_start_locking" },
	{ 0xdc15c2d5, "__mmap_lock_do_trace_acquire_returned" },
	{ 0x675e0580, "__mmap_lock_do_trace_released" },
	{ 0x516f3cba, "dma_buf_put" },
	{ 0x278b2ee3, "alloc_pages" },
	{ 0x941f2aaa, "eventfd_ctx_put" },
	{ 0xd67364f7, "eventfd_ctx_fdget" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x2ef187dc, "dma_buf_fd" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0xf4e234d8, "dma_buf_export" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x53b954a2, "up_read" },
	{ 0xda193443, "__tracepoint_mmap_lock_released" },
	{ 0xb3d0db62, "pin_user_pages" },
	{ 0x4ade2828, "__tracepoint_mmap_lock_acquire_returned" },
	{ 0x668b19a1, "down_read" },
	{ 0xe97588c8, "__tracepoint_mmap_lock_start_locking" },
	{ 0x85b33882, "current_task" },
	{ 0x20978fb9, "idr_find" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x5776fd17, "__free_pages" },
	{ 0xd23215db, "unpin_user_page" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x81fcfa48, "pv_ops" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x23fbf5e0, "dma_map_sgtable" },
	{ 0xab303bd4, "sg_alloc_table_from_pages_segment" },
	{ 0x3a2f6702, "sg_alloc_table" },
	{ 0xcbb0ae81, "kmem_cache_alloc_trace" },
	{ 0x58f94a7a, "kmalloc_caches" },
	{ 0x10fb2471, "vm_insert_page" },
	{ 0x50d1f870, "pgprot_writecombine" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x9fa51ada, "vmap" },
	{ 0xd38cd261, "__default_kernel_pte_mask" },
	{ 0x8a35b432, "sme_me_mask" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x94961283, "vunmap" },
	{ 0x37a0cba, "kfree" },
	{ 0x7f5b4fe4, "sg_free_table" },
	{ 0x48fae65e, "dma_unmap_sg_attrs" },
	{ 0xd033aa56, "boot_cpu_data" },
	{ 0xc60d0620, "__num_online_cpus" },
	{ 0x81e6b37f, "dmi_get_system_info" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xdf0f75c6, "eventfd_signal" },
	{ 0xa0d3456d, "nr_swap_pages" },
	{ 0x40c7247c, "si_meminfo" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x92997ed8, "_printk" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "AD02EBBB2B1C840B7E2A689");
