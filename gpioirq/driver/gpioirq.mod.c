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
	{ 0x61d10787, __VMLINUX_SYMBOL_STR(platform_driver_unregister) },
	{ 0xd5e047f2, __VMLINUX_SYMBOL_STR(__platform_driver_register) },
	{ 0xd85cd67e, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0xd6b8e852, __VMLINUX_SYMBOL_STR(request_threaded_irq) },
	{ 0x96251fff, __VMLINUX_SYMBOL_STR(platform_get_resource) },
	{ 0xdadb74c8, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x4d2d6bc9, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0xdfd5d164, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x353e0e0e, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0xf4fa543b, __VMLINUX_SYMBOL_STR(arm_copy_to_user) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0xac2d86d3, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x9a6164de, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0xf84d6b97, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0xf20dabd8, __VMLINUX_SYMBOL_STR(free_irq) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("of:N*T*Cmy_gpio_irq*");

MODULE_INFO(srcversion, "1703333571CB260E08335FD");
