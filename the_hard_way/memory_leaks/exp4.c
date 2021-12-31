#include <stdio.h>
#include <stdlib.h>

// Write a program that reads a file of strings, allocate memory for each string dynamically, and store the strings in an array of char pointers, caculate the memory usage by your program using sizeof operator

// valgrind --leak-check=full -v ./exp4

int main() {
	FILE * fp;
	char * line  = malloc(6 * sizeof(char));
	size_t len = 0;
	ssize_t read;

	fp = fopen("test_file","r");

	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fp)) != -1) {
		printf("Lenght: %zu, %zu\n", read,len);

		printf("%s",line);
	}
	printf("Space: %d\n",sizeof(line));
	fclose(fp);

	if (line) {
		free(line);
	}
	exit(EXIT_SUCCESS);
}
