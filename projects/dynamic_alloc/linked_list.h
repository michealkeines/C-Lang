#ifndef __LL_H_
#define __LL_H_

#include <stdlib.h>

#ifndef offsetof
    #ifdef __compiler_offsetof
        #define offsetof(TYPE, MEMBER) __complier_offsetof(TYPE, MEMBER)
    #else   
        #define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)
    #endif
#endif // END offsetof

#ifndef container_of
    #define container_of(ptr, type, member)                    \
        ({                                                      \
            const __typeof__(((type *)0)->member) *__mptr = (ptr); \
            (type *)((char *)__mptr - offsetof(type, member));        \
        })
#endif // END container_of

// Doubly Linked List

typedef struct ll_head
{
    struct ll_head* next;
    struct ll_head* prev;
} ll_t;

#define list_entry(ptr, type, member) container_of(ptr, type, member)

#define list_first_entry(head, type, member) list_entry((head)->next, type, member)

#define list_for_each(pos, n, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_for_each_safe(pos, n, head) \
    for (pos = (head)->next, n = pos->next; pos != (head); pos = n, n = pos->next)

#endif // END __LL_H_
