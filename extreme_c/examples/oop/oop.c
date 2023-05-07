#include <stdio.h>
#include "oop.h"

bool_t list_is_full(list_t *list)
{
    if (list_size(list) == MAX_SIZE)
    {
        return TRUE;
    }
    return FALSE;
}

bool_t list_check_index_in_range(list_t *list, size_t index)
{
    if (index < MAX_SIZE)
    {
        return TRUE;
    }
    return FALSE;
}

list_t *list_allocate(void)
{
    return (list_t *) malloc(sizeof(list_t));
}

bool_t list_add(list_t *list, uint64_t value)
{
    if (list_is_full(list))
    {
        return FALSE;
    }

    list->values[list->size] = value;
    list->size++;

    return TRUE;
}

bool_t list_get(list_t *list, size_t index, uint64_t *out)
{
    if (list_check_index_in_range(list, index))
    {
        *out = list->values[index];
        return TRUE;
    }

    return FALSE;
}

void list_clean(list_t *list)
{
    list->size = 0;
}

size_t list_size(list_t *list)
{
    return list->size;
}

void list_initialize(list_t *list)
{
    list->size = 0;
    list->values = (uint64_t *) malloc(sizeof(uint64_t) * MAX_SIZE);
}

void list_destory(list_t *list)
{
    if(list != NULL)
    {
        free(list);
    }
}

void list_print(list_t *list)
{
    printf("[ ");
    
    for(size_t i = 0; i < list->size; i++)
    {
        if (i == (list->size - 1)) 
        {
            printf("%d ", list->values[i]);
        } 
        else 
        {
            printf("%d, ", list->values[i]);
        }
  
    }
    
    printf("]\n");
}

int main()
{
    list_t *list = list_allocate();
    list_initialize(list);
    
    list_add(list, 3);
    list_add(list, 7);
    list_add(list, 5);

    uint64_t temp;

    if (list_get(list, 2, &temp)) 
    {
        printf("val: %d\n", temp);
    }

    if (list_get(list, 20, &temp)) 
    {
        printf("val: %d\n", temp);
    }


    if (list_get(list, 120, &temp)) 
    {
        printf("val: %d\n", temp);
    }

    list_print(list);
    list_clean(list);
    list_destory(list);

    return 0;
}