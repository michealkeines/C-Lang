#include<stdio.h>

int main(int argc, char *argv[]) {
	int i = 1;

	if (argc == 1) {
		printf("You only have one argument. You Suck. \n");
	} else if (argc > 2 && argc < 5) {
		printf("Here's your arguments: ");

		for (;i < argc; i++) {
			printf("%s ", argv[i]);
		}
		printf("\n");
	} else {
		printf("You have too many arguments. You Suck Too. \n");
	}

	return 0;
}
