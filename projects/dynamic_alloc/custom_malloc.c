#include <stdlib.h>

typedef struct {
    ll_t node;
    size_t size;
    char *block;
} alloc_node_t;

void 
malloc_addblock(void *addr, size_t size)
{
    alloc_node_t *blk;
    
    blk = (void *) align_up((uintptr_t) addr, sizeof(void *));

    blk->size = (uintptr_t) addr + size - (uintptr_t) blk - ALLOC_HEADER_SZ;

    list_add(&blk->node, &free_list);
}