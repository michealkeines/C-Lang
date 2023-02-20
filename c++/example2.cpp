#include <stdio.h>

int main()
{
    int a = 10;
    int b = 12;

    int *pointer_to_a = &a;
    int *pointer_to_b = &b;

    int c = *pointer_to_a;
    int d = *pointer_to_b;

    printf("a: %d\n", a);
    printf("address of a: %p\n", pointer_to_a);
    printf("address of b: %p\n", pointer_to_b);
    printf("c: %d\n", c);
    printf("d: %d\n", d);
    
    return 0;
}



/*

    0x1 (a) = 10
    0x4 (b) = 12
    0x8 (pointer_to_a) = 0x1
    0x10 (pointer_to_b) = 0x4

    0x12 (c) = 10

    0xfffffff

*/