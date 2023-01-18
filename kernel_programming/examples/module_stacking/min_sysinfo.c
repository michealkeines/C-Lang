#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/limits.h>

MODULE_AUTHOR("Micheal Keines");
MODULE_DESCRIPTION("Minimum system info module");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.0.1");

#define MODULENAME "minsysinfo"


void llkd_sysinfo(void)
{
    char msg[128];

    memset(msg, 0, strlen(msg));

    snprintf(msg, 48, "\n%s(): platform information:\nCPU: ", __func__);

#ifdef CONFIG_X86
#if (BITS_PER_LONG == 32)
    strncat(msg, "x86_32, ", 9);
#else
    strncat(msg, "x86_64, ", 9);
#endif
#endif

#ifdef __BIG_ENDIAN
    strncat(msg, "big-endian; ", 13);
#else
    strncat(msg, "little-endian; ", 16);
#endif
    pr_info("%s\n", msg);
}

EXPORT_SYMBOL_GPL(llkd_sysinfo);



static int __init min_sysinfo_init(void)
{
    pr_info("%s: inserted\n", MODULENAME);
    
    // llkd_sysinfo();

    return 0;
}

static void __exit min_sysinfo_exit(void)
{
    pr_info("%s: removed\n", MODULENAME);
}

module_init(min_sysinfo_init);
module_exit(min_sysinfo_exit);