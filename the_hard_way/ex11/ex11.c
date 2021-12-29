#include <stdio.h>
#include <ctype.h>

int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[]) {
	int i = 0;
	for (i = 0; i < argc; i++) {
		print_letters(argv[i]);
	}
}

void print_letters(char arg[]) {
	int i = 0;
	for (i=0; arg[i] != '\0'; i++) {
		char ch = arg[i];
		if (can_print_it(ch)) {
			printf("%c(%d) ", ch, ch);
		}
	}
	printf("\n");
}

int can_print_it(char ch) {
	return isalpha(ch) || isblank(ch);
}

void pointers() {
	int ages[] = { 32, 34,23,24,27 };
	char *names[] = {
		"person1", "person2", "person3", "person4", "person5"
	};

	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	for (i = 0; i < count; i++) {
		printf("%s has %d years alive.\n",names[i], ages[i]);
	}

	printf("---\n");

	int *cur_age = ages;
	char **cur_name = names;

	printf("%d\n",*ages);
	printf("%d\n",*(ages+4));
	printf("%d\n",*(ages+4));
	printf("%d\n",*(ages+4));

	for (i=0; i<count; i++) {
		printf("%s is %d years old.\n", *(cur_name+i), *(cur_age + 1));
	}

	printf("--\n");
	for (i = 0; i < count; i++) {
		printf("%s lived %d years old again.\n", cur_name[i], cur_age[i]);
	}

	printf("--\n");

	for (cur_name = names, cur_age = ages; (cur_age-ages) < count; cur_name++, cur_age++) {
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}
}



int main(int argc, char *argv[]) {
//	int number[4] = { 0, 2,3 ,4 };
//	char name[9] = { 'a', 't','t','a','c','k','\0' };
//
//	printf("numbers: %d, %d, %d, %d\n", number[0], number[1], number[2], number[3]);
//	printf("chars: %c, %c, %c, %c\n", name[0], name[1], name[2], name[3]);
//	printf("name: %s\n", name);
//	char *str = "time";

//	printf("test: %s\n",str);

//	int test[] = { 12, 12, 13, 15, 17}; 
//	char name[] = "Kaines";
//	char full_name[] = { 
//		'M','i','c','h','e','a','l','\0'
//	};

//	printf("The size of int: %ld\n", sizeof(int));
//	printf("The size of test: %ld\n", sizeof(test));
//	printf("The number of ints in areas: %ld\n", sizeof(test)/ sizeof(int));
//
///	printf("the size of char: %ld\n", sizeof(char));
//	printf("the size of name: %ld\n", sizeof(name));
//	printf("the number of chars: %ld\n", sizeof(name)/sizeof(char));
//	printf("The size of fullname: %ld\n", sizeof(full_name));
//	printf("The number of chars: %ld\n", sizeof(full_name)/sizeof(char));
///	print_arguments(argc, argv);
	pointers();
	return 0;
}
