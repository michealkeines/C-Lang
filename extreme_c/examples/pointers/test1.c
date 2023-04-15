#include <stdio.h>
#include <stdint.h>


int main()
{
    uint64_t counter1 = 3;
    uint64_t counter2 = 6;
    uint64_t counter3 = 9;

    printf("initial address: %x, %x, %x\n", &counter1, &counter2, &counter3);

    uint64_t *count_ptr = NULL;
    count_ptr = &counter3;
    printf("current: %d, address:%x ptr: %d\n", counter2, count_ptr, *count_ptr);
    count_ptr = (++count_ptr);
    printf("current: %d, address:%x ptr: %d\n", counter2, count_ptr, *count_ptr);
    count_ptr = (++count_ptr);
    printf("current: %d, address:%x ptr: %d\n", counter2, count_ptr, *count_ptr);

    return 0;
}