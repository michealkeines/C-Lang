#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *fp = fopen("argv[1]", "r"); // argv[1] is in quotation thus passed as the filename instead of a variable, this causes file not found seg fault
	char *word;
	while (fscanf(fp, "%s", word) > 0){}
	printf("%s\n",word);
	return 0;
}
