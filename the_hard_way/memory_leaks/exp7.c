#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]) {
	int i = 0;
	int n = 2;
	char a;
	char b;
	char name[32];
	char * A[n];
	A[0] = &a;
	A[1] = &b;
	printf("n var address %p\n",&n);
	printf("name var address %p\n",&name);
	printf("A var address %p\n",&A);

	FILE * infile = fopen(argv[1], "r");
//	char test[] = "Aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
//	strcpy(A[0],test);
	while (fscanf(infile, "%s", name) > 0) {
		printf("len %u\n",strlen(name)); 
		// if the length of the input from the file is more than some byte, it seg faults
		strcpy(A[i++], name);
		printf("after %s\n",A[i++]);
	}

	for (int j=i; j>0; j--) {
		A[i+1] = A[i];
	}
}

