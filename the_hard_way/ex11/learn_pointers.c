#include<stdio.h>

int main() {
	int ages[] = { 1,2,3,4,5 };

	int *temp = ages;
	printf("size of ages: %d\n",sizeof(ages));
	printf("%d\n",*(temp));
	printf("%d\n",*(temp+1));
	printf("%d\n",*(temp+2));
	printf("%d\n",*(temp+3));
	printf("%d\n",*(temp+4));

	char *names[] = { "person1", "person2", "person3", "person4", "person5" };

	char **nam = names;

	printf("size of names: %d\n", sizeof(names));
	printf("%s\n",*(nam));
	printf("%s\n",*(nam+1));
	printf("%s\n",*(nam+2));
	printf("%s\n",*(nam+3));
	printf("%s\n",*(nam+4));

	printf("%s\n",*(names)); // person1
	printf("%s\n",names[2]); // person3
	printf("%c\n",*(names)[1]); // p
	printf("%c\n",*(*(names)+1)); // e

	return 0;
}
