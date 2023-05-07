#ifndef __OOP__HEADER
#define __OOP__HEADER

#include <stdlib.h>
#include <stdint.h>

#define MAX_SIZE 98
#define TRUE 1
#define FALSE 0

typedef uint8_t bool_t;

typedef struct {
    uint64_t *values;
    size_t size;
} list_t;

bool_t  list_is_full(list_t *);
bool_t  list_check_index_in_range(list_t *, size_t index);
bool_t  list_add(list_t *, uint64_t value);
bool_t  list_get(list_t *, size_t index, uint64_t *out);
list_t *list_allocate(void);
size_t  list_size(list_t *);
void    list_clean(list_t *);
void    list_initialize(list_t *);
void    list_destory(list_t *);
void    list_print(list_t *);

#endif