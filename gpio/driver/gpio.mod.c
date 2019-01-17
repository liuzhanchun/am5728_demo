#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x4f3b2228, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xac2d86d3, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x9a6164de, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0xf84d6b97, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0xedc03953, __VMLINUX_SYMBOL_STR(iounmap) },
	{ 0x42ecf546, __VMLINUX_SYMBOL_STR(ioremap) },
	{ 0xdadb74c8, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x4d2d6bc9, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0xdfd5d164, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x353e0e0e, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0xf4fa543b, __VMLINUX_SYMBOL_STR(arm_copy_to_user) },
	{ 0x28cc25db, __VMLINUX_SYMBOL_STR(arm_copy_from_user) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "E9FB2DE51596CFD079A0D4C");
