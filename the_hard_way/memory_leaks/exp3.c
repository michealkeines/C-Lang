#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
int main() {
        printf("%ld\n",INT_MAX);
        int n = INT_MAX;
        int A[n]; // this overflows the stack
        int i = 0;

        while (i<n) {
            A[i] = rand() % 10;                                                                                                
            i = i + 1;
        }
        printf("over");
        return 0;
}

