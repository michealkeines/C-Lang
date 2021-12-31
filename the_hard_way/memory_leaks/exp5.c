#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
	char * name = malloc(1 * sizeof(char));
	char a = 'A';
	name = strcpy(name, &a);
	//free(name);
//	printf("%s \n", *name); // directly dereferencing a variable take the value inside the variable as the address and tries to get the value in that address
	printf("%s \n", *(&name)); // now we pass the address of the variable, i will get the value inside the address
	return EXIT_SUCCESS;
}
