#include <stdio.h>
#include <stdlib.h>

void foo(int *** array);

int main(int argc, char * argv[]) {
	//int t = 10;
//	int * p = &t;
///	int ** A = &p;
///	printf("variable A at location %p has a value which is location that is the value of variable in this %p that points to an integer\n",&A,&p);
//	printf("value inside variable A %p\n",*A);
//	printf("value inside location foudn in A %d\n",*(*A));
	//int ** A = (int **) malloc(10 * sizeof(int*)); if we intialize this here, we can prevent the segfault
	int ** A; // this is empty 0x00000000, thus we will get seg fault when we dereference it
	foo(&A);
	return 0;
}

void foo(int *** array) {
	int n = 5;
	int ** arrayint = (int **) malloc(2 * n * sizeof(int *));
	for(int i = 0; i < n; i++) {
		arrayint[i] = (*array)[i]; // as our intial array is not pointing to any location, it contains 0x00000000 dereferencing that causing segfault
	}
	free(*array);
	array = &arrayint;
}

