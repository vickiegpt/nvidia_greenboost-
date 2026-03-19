#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

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



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd648ae19, "sg_free_table" },
	{ 0xcb8b6ec6, "kfree" },
	{ 0xf1de9e85, "vunmap" },
	{ 0x9aa6980d, "mutex_init_generic" },
	{ 0x9f222e1e, "alloc_chrdev_region" },
	{ 0x2a8cbeb2, "cdev_init" },
	{ 0xa7c43d7e, "cdev_add" },
	{ 0x2f11914a, "class_create" },
	{ 0x2219d793, "device_create_with_groups" },
	{ 0x3314ac7c, "kthread_create_on_node" },
	{ 0x68708f50, "wake_up_process" },
	{ 0x227d0734, "device_destroy" },
	{ 0xf2aabb37, "alloc_cpumask_var_node" },
	{ 0xf296206e, "nr_cpu_ids" },
	{ 0xb5c51982, "__cpu_online_mask" },
	{ 0x494c552b, "_find_first_bit" },
	{ 0x3887bc1e, "set_cpus_allowed_ptr" },
	{ 0x02b7fa5b, "free_cpumask_var" },
	{ 0xe5061eb1, "class_destroy" },
	{ 0xa2b93c09, "cdev_del" },
	{ 0x0bc5fb0d, "unregister_chrdev_region" },
	{ 0xe0418251, "eventfd_ctx_put" },
	{ 0xc52f2ae0, "kthread_stop" },
	{ 0xfc66744b, "idr_destroy" },
	{ 0x5af09d8b, "_raw_spin_lock" },
	{ 0x5af09d8b, "_raw_spin_unlock" },
	{ 0x9aa6980d, "mutex_lock" },
	{ 0x6b412821, "idr_remove" },
	{ 0x9aa6980d, "mutex_unlock" },
	{ 0x6bcc1d33, "unpin_user_page" },
	{ 0xf1de9e85, "kvfree" },
	{ 0x94e3c3dc, "__free_pages" },
	{ 0xe4de56b4, "__ubsan_handle_load_invalid_value" },
	{ 0x7ff38994, "__kvmalloc_node_noprof" },
	{ 0x1bdf2bc8, "sme_me_mask" },
	{ 0x5fc55113, "__default_kernel_pte_mask" },
	{ 0x1447b25c, "vmap" },
	{ 0x5e865cb8, "pgprot_writecombine" },
	{ 0x21176902, "vm_insert_page" },
	{ 0xbd03ed67, "random_kmalloc_seed" },
	{ 0x311f460c, "kmalloc_caches" },
	{ 0x3fdaf7d4, "__kmalloc_cache_noprof" },
	{ 0xb09bc67d, "sg_alloc_table" },
	{ 0xccc2d251, "sg_alloc_table_from_pages_segment" },
	{ 0x8bf26af4, "dma_map_sgtable" },
	{ 0x092a35a2, "_copy_from_user" },
	{ 0x3c0300ea, "eventfd_ctx_fdget" },
	{ 0x9c66e76b, "const_current_task" },
	{ 0xfc3a54ba, "__tracepoint_mmap_lock_start_locking" },
	{ 0x8efcc8cd, "down_read" },
	{ 0xfc3a54ba, "__tracepoint_mmap_lock_acquire_returned" },
	{ 0x20fa183f, "pin_user_pages" },
	{ 0xfc3a54ba, "__tracepoint_mmap_lock_released" },
	{ 0x8efcc8cd, "up_read" },
	{ 0x058c185a, "jiffies" },
	{ 0x9b1ec61b, "dma_buf_export" },
	{ 0xb33f96dc, "idr_alloc" },
	{ 0x9c23d8f7, "dma_buf_fd" },
	{ 0x092a35a2, "_copy_to_user" },
	{ 0x9a8a840e, "idr_find" },
	{ 0x9fe9f42d, "alloc_pages_noprof" },
	{ 0x59deb3aa, "dma_buf_put" },
	{ 0xa118cb55, "__mmap_lock_do_trace_released" },
	{ 0xa118cb55, "__mmap_lock_do_trace_start_locking" },
	{ 0x0526cb2f, "__mmap_lock_do_trace_acquire_returned" },
	{ 0x7fcaefd1, "param_ops_int" },
	{ 0xd272d446, "__fentry__" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0xe8213e80, "_printk" },
	{ 0xbd03ed67, "__ref_stack_chk_guard" },
	{ 0x5e505530, "kthread_should_stop" },
	{ 0x5723059f, "msleep_interruptible" },
	{ 0xc7ffe1aa, "si_meminfo" },
	{ 0xf654f750, "nr_swap_pages" },
	{ 0x18ded256, "eventfd_signal_mask" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0xdd6830c7, "sysfs_emit" },
	{ 0xfdfc89f8, "dmi_get_system_info" },
	{ 0xb6d2afcd, "__num_online_cpus" },
	{ 0xb1ad3f2f, "boot_cpu_data" },
	{ 0x9f2e5441, "dma_unmap_sg_attrs" },
	{ 0x2e7d9e3a, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0xd648ae19,
	0xcb8b6ec6,
	0xf1de9e85,
	0x9aa6980d,
	0x9f222e1e,
	0x2a8cbeb2,
	0xa7c43d7e,
	0x2f11914a,
	0x2219d793,
	0x3314ac7c,
	0x68708f50,
	0x227d0734,
	0xf2aabb37,
	0xf296206e,
	0xb5c51982,
	0x494c552b,
	0x3887bc1e,
	0x02b7fa5b,
	0xe5061eb1,
	0xa2b93c09,
	0x0bc5fb0d,
	0xe0418251,
	0xc52f2ae0,
	0xfc66744b,
	0x5af09d8b,
	0x5af09d8b,
	0x9aa6980d,
	0x6b412821,
	0x9aa6980d,
	0x6bcc1d33,
	0xf1de9e85,
	0x94e3c3dc,
	0xe4de56b4,
	0x7ff38994,
	0x1bdf2bc8,
	0x5fc55113,
	0x1447b25c,
	0x5e865cb8,
	0x21176902,
	0xbd03ed67,
	0x311f460c,
	0x3fdaf7d4,
	0xb09bc67d,
	0xccc2d251,
	0x8bf26af4,
	0x092a35a2,
	0x3c0300ea,
	0x9c66e76b,
	0xfc3a54ba,
	0x8efcc8cd,
	0xfc3a54ba,
	0x20fa183f,
	0xfc3a54ba,
	0x8efcc8cd,
	0x058c185a,
	0x9b1ec61b,
	0xb33f96dc,
	0x9c23d8f7,
	0x092a35a2,
	0x9a8a840e,
	0x9fe9f42d,
	0x59deb3aa,
	0xa118cb55,
	0xa118cb55,
	0x0526cb2f,
	0x7fcaefd1,
	0xd272d446,
	0xd272d446,
	0xe8213e80,
	0xbd03ed67,
	0x5e505530,
	0x5723059f,
	0xc7ffe1aa,
	0xf654f750,
	0x18ded256,
	0xd272d446,
	0xdd6830c7,
	0xfdfc89f8,
	0xb6d2afcd,
	0xb1ad3f2f,
	0x9f2e5441,
	0x2e7d9e3a,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"sg_free_table\0"
	"kfree\0"
	"vunmap\0"
	"mutex_init_generic\0"
	"alloc_chrdev_region\0"
	"cdev_init\0"
	"cdev_add\0"
	"class_create\0"
	"device_create_with_groups\0"
	"kthread_create_on_node\0"
	"wake_up_process\0"
	"device_destroy\0"
	"alloc_cpumask_var_node\0"
	"nr_cpu_ids\0"
	"__cpu_online_mask\0"
	"_find_first_bit\0"
	"set_cpus_allowed_ptr\0"
	"free_cpumask_var\0"
	"class_destroy\0"
	"cdev_del\0"
	"unregister_chrdev_region\0"
	"eventfd_ctx_put\0"
	"kthread_stop\0"
	"idr_destroy\0"
	"_raw_spin_lock\0"
	"_raw_spin_unlock\0"
	"mutex_lock\0"
	"idr_remove\0"
	"mutex_unlock\0"
	"unpin_user_page\0"
	"kvfree\0"
	"__free_pages\0"
	"__ubsan_handle_load_invalid_value\0"
	"__kvmalloc_node_noprof\0"
	"sme_me_mask\0"
	"__default_kernel_pte_mask\0"
	"vmap\0"
	"pgprot_writecombine\0"
	"vm_insert_page\0"
	"random_kmalloc_seed\0"
	"kmalloc_caches\0"
	"__kmalloc_cache_noprof\0"
	"sg_alloc_table\0"
	"sg_alloc_table_from_pages_segment\0"
	"dma_map_sgtable\0"
	"_copy_from_user\0"
	"eventfd_ctx_fdget\0"
	"const_current_task\0"
	"__tracepoint_mmap_lock_start_locking\0"
	"down_read\0"
	"__tracepoint_mmap_lock_acquire_returned\0"
	"pin_user_pages\0"
	"__tracepoint_mmap_lock_released\0"
	"up_read\0"
	"jiffies\0"
	"dma_buf_export\0"
	"idr_alloc\0"
	"dma_buf_fd\0"
	"_copy_to_user\0"
	"idr_find\0"
	"alloc_pages_noprof\0"
	"dma_buf_put\0"
	"__mmap_lock_do_trace_released\0"
	"__mmap_lock_do_trace_start_locking\0"
	"__mmap_lock_do_trace_acquire_returned\0"
	"param_ops_int\0"
	"__fentry__\0"
	"__x86_return_thunk\0"
	"_printk\0"
	"__ref_stack_chk_guard\0"
	"kthread_should_stop\0"
	"msleep_interruptible\0"
	"si_meminfo\0"
	"nr_swap_pages\0"
	"eventfd_signal_mask\0"
	"__stack_chk_fail\0"
	"sysfs_emit\0"
	"dmi_get_system_info\0"
	"__num_online_cpus\0"
	"boot_cpu_data\0"
	"dma_unmap_sg_attrs\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6CDEF5D11F5299573C1CEC1");
