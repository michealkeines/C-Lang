#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
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
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0x9cb986f2, "vmalloc_base" },
	{ 0x8a7d1c31, "high_memory" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x19b41819, "pcpu_hot" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xf01763da, "param_ops_int" },
	{ 0x6028c307, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "9C32C713DCC13EB38BC855B");
