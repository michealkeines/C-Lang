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
	{ 0xe914e41e, "strcpy" },
	{ 0x96c007e9, "kmem_cache_destroy" },
	{ 0x3110a822, "kmem_cache_create" },
	{ 0x7c0dcd56, "kmem_cache_alloc" },
	{ 0x4ea5d10, "ksize" },
	{ 0xc7c83200, "kmem_cache_size" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0x8ae5e9aa, "kmem_cache_free" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x783b1f20, "param_ops_uint" },
	{ 0x6028c307, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D9010836E281398471CD30F");
