#include <stdlib.h>
#include "linked_list.h"

#pragma mark -- Definitions --

#ifndef align_up
    #define align_up(num, align) (((num) + ((align) - 1)) & ~((align) - 1))
#endif

typedef struct
{
    ll_t node;
    size_t size;
    char *block;
} alloc_node_t;

#define ALLOC_HEADER_SZ offsetof(alloc_node_t, block)

#define MIN_ALLOC_SZ ALLOC_HEADER_SZ + 32

#pragma mark -- Prototypes --

static void defrag_free_list(void);

#pragma mark -- Declarations --

static LIST_INIT(free_list);

#pragma mark -- Private Function --

void defrag_free_list(void)
{
    alloc_node_t *block, *last_block = NULL, *t;

    list_for_each_entry_safe(block, t, &free_list, node)
    {
        if (last_block)
        {
            if ((((uintptr_t) &last_block->block) + last_block->size) == (uintptr_t) block)
            {
                last_block->size += ALLOC_HEADER_SZ + block->size;
                list_del(&block->node);
                continue;
            }
        }
    }
}

#pragma mark -- APIs --

void *fl_malloc(size_t size)
{
    void *ptr = NULL;
    alloc_node_t *blk = NULL;

    if (size > 0)
    {
        size = align_up(size, sizeof(void*));

        list_for_each_entry(blk, &free_list, node)
        {
            if (blk->size >= size)
            {
                ptr = &blk->block;
                break;
            }
        }

        if (ptr)
        {
            if((blk->size - size) >= MIN_ALLOC_SZ)
            {
                alloc_node_t *new_blk;
                new_blk = (alloc_node_t*)((uintptr_t)(&blk->block + size));
                new_blk->size = blk->size - size - ALLOC_HEADER_SZ;
                blk->size = size;
                list_add_(&new_blk->node, &blk->node, blk->node.next);
            }

            list_del(&blk->node);
        }
    }

    return ptr;
}

void fl_free(void *ptr)
{
    alloc_node_t *blk, *free_blk;

    if (ptr)
    {
        blk = container_of(ptr, alloc_node_t, block);

        list_for_each_entry(free_blk, &free_list, node)
        {
            if (free_blk > blk)
            {
                list_add_(&blk->node, free_blk->node.prev, &free_blk->node);
                goto blockadded;
            }
        }

        list_add_tail(&blk->node, &free_list);

    blockadded:
        defrag_free_list();
    }

}

void malloc_addblock(void *addr, size_t size)
{
    alloc_node_t *blk;

    blk = (void*) align_up((uintptr_t)addr, sizeof(void*));

    blk->size = (uintptr_t) addr + size - (uintptr_t) blk - ALLOC_HEADER_SZ;

    list_add(&blk->node, &free_list);
}
