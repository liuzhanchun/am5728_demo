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
	{ 0x8a3f725f, __VMLINUX_SYMBOL_STR(i2c_del_driver) },
	{ 0x26f8e13d, __VMLINUX_SYMBOL_STR(i2c_register_driver) },
	{ 0xf9a482f9, __VMLINUX_SYMBOL_STR(msleep) },
	{ 0xbabc000c, __VMLINUX_SYMBOL_STR(i2c_smbus_write_byte_data) },
	{ 0xdfd5d164, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x353e0e0e, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0xa4e6e50a, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0x8aefe310, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd8e484f0, __VMLINUX_SYMBOL_STR(register_chrdev_region) },
	{ 0xf4fa543b, __VMLINUX_SYMBOL_STR(arm_copy_to_user) },
	{ 0x65f18bb9, __VMLINUX_SYMBOL_STR(i2c_smbus_read_word_data) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xac2d86d3, __VMLINUX_SYMBOL_STR(cdev_del) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("i2c:mpu6050");

MODULE_INFO(srcversion, "61CBF71874075BCF9A1CE4D");
