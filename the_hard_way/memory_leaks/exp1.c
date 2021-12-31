#include <stdio.h>

int main(int argc, char* argv[]) {
	int x;
	printf("Please enter an integer: ");
	scanf("%d",x); // this will lead to seg fault as we are using variable instead of its address
	printf("the integer entered was %d \n", x);
	return 1;
}
