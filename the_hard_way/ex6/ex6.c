#include <stdio.h>
#include <stdlib.h>

int if_statement() {
	short value = 1;
	
	if (value == 1) {
		return 1;
	} else {
		return 0;
	}

}

void switch_statement(int value) {
	switch (value) {
		case 1:
			printf("value: %i\n",value);
			break;
		default:
			printf("Something went wrong!\n");
	}
}

char * while_statement(int limit) {
	char *string;
	string = malloc(limit * sizeof(char));
	while (limit >= 0) {
		string[limit] = limit+70;
		limit -= 1;
	}
	return string;
}

char * do_while_statement(int limit) {
	char *string;
	string = malloc(limit * sizeof(char));

	do {
		string[limit] = limit + 80;
		limit -= 1;
	} while (limit >= 0);

	return string;
}

void for_loop() {
	for (int i = 90; i < 100; i++) {
		printf("%c",i);
	}
	printf("\n");
}

enum {
	True = 1, False = 0
} test;

typedef unsigned int u32;

typedef struct store {
	int value;
} count;

int main(int argc, char* argv[]) {	
	if (True) {
		printf("Inside Condition \n");
		count i;
		i.value = 1;
		printf("Store count: %u\n",i.value);
	}
	switch_statement(1);
	if (if_statement()) {
		printf("%s\n",while_statement(10));
		printf("%s\n",do_while_statement(5));
	
	}
	for_loop(5);

	return 0;
}
