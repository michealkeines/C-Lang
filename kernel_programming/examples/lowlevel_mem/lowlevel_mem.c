#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/mm.h>
#include "./klib_llkd.h"

#define MOD_NAME "lowlevel_mem"

MODULE_DESCRIPTION("make use of kernel page allocater apis");
MODULE_AUTHOR("Micheal Keines");
MODULE_LICENSE("GPL");

static const void *gptr1, *gptr2, *gptr3, *gptr4, *gptr5;
static int bsa_alloc_order = 3;
static int order = 0;
module_param_named(order, bsa_alloc_order, int, 0660);
MODULE_PARM_DESC(order, "order of the allocation (power to raise by 2)");

static int base_alloc(void)
{
    int stat = -ENOMEM;
    u64 power_val = 0;
    const struct page *pg_ptr1;

    pr_info("%s: 0. show identity mapping: RAM page frames : kernel virtual pages:: 1:1\n", MOD_NAME);

    show_phy_pages((void *) PAGE_OFFSET, 5 * PAGE_SIZE, 1);

    gptr1 = (void *) __get_free_page(GFP_KERNEL);

    if (!gptr1) {
        pr_warn("%s: __get_free_page() failed\n", MOD_NAME);
        goto out1;
    }

    pr_info("%s: 1 __get_free_page() alloced 1 page from the BSA @ %pK (%px)\n", MOD_NAME, gptr1, gptr1);

    power_val = powerof(2, bsa_alloc_order);

    gptr2 = (void *) __get_free_pages(GFP_KERNEL | __GFP_ZERO, bsa_alloc_order);
    if (!gptr2) {
        goto out2;
    }

    pr_info("%s: 2. __get_free_pages() allocated 2^%d = %lld pages = %lld bytes\n",
        " from the BSA @ %pK (%px)\n",
        MOD_NAME, bsa_alloc_order, powerof(2, bsa_alloc_order), power_val * PAGE_SIZE, gptr2, gptr2
    );

    pr_info("PAGE_SIZE = %ld bytes\n", PAGE_SIZE);
    show_phy_pages(gptr2, power_val * PAGE_SIZE, 1);

    gptr3 = (void *) get_zeroed_page(GFP_KERNEL);

    if(!gptr3) {
        goto out3;
    }

    pr_info("%s: 3. get_zerored_page() alloced 1 page from the BSA @ %pK (%px)\n", MOD_NAME, gptr3, gptr3);

    pg_ptr1 = alloc_page(GFP_KERNEL);

    if (!pg_ptr1) {
        goto out4;
    }

    gptr4 = page_address(pg_ptr1);

    pr_info("%s: 4. alloc_page() allocated 1 page from the BSA @ %pK (%px)\n"
        " (struct page addr=%pK (%px))\n",
        MOD_NAME, (void *) gptr4, (void *) gptr4, pg_ptr1, pg_ptr1
    );

    gptr5 = page_address(alloc_pages(GFP_KERNEL, 5));

    if (!gptr5) {
        goto out5;
    }

    pr_info("%s: 5. alloc_pages alloced %lld pages from the BSA @ %pK (%px)\n", MOD_NAME, powerof(2, 5), (void *) gptr5,
        (void *) gptr5
    );

    return 0;

out5:
    free_page((unsigned long) gptr4);
out4:
    free_page((unsigned long) gptr3);
out3:
    free_pages((unsigned long) gptr2, bsa_alloc_order);
out2:
    free_page((unsigned long) gptr1);
out1:
    return stat;
}

static int __init lowlevel_mem_init(void)
{
    return base_alloc();
}

static void __exit lowlevel_mem_exit(void)
{
    pr_info("%s: freeing up the memory chunks..\n", MOD_NAME);
    free_pages((unsigned long) gptr5, 3);
    free_page((unsigned long) gptr4);
    free_page((unsigned long) gptr3);
    free_pages((unsigned long) gptr2, bsa_alloc_order);
    free_page((unsigned long) gptr1);
    pr_info("%s: removed\n", MOD_NAME);
}


module_init(lowlevel_mem_init);
module_exit(lowlevel_mem_exit);
