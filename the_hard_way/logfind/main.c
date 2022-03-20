#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void search_string(char ** input_strings, int input_len, bool match_or) {
	for (int i = 0; i < input_len; i++) {
		printf("%s\n", input_strings[i]);
	}


}

int main(int argc, char ** argv) {
	printf("Log Finder v1.0\n");
	if (argc < 2) {
	help_jump:
		printf("Usage: logfinder <string to search>\n\n");
		printf("Options:\n\t-o to match with OR condition (AND by default)\n");
		return 0;
	}

	int MATCH_OR = 0;
	int option_count = 0;

	for (int i = 1; i < argc; i++) {
		//printf("%s\n", argv[i]);
		if (strlen(argv[i]) == 2 && argv[i][0] == '-') {
			char temp = argv[i][1];
			switch (temp) {
				case 'o':
					MATCH_OR = 1;
					option_count += 1;
					break;
				case 'h':
					goto help_jump;
				default:
					printf("Invalid Option, Try -h for Help.\n");
					return 0;

			}
		}
	}

	int input_len = argc - (option_count + 1);

	char * input_strings[input_len];
	int j = 0;
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i],"-o") != 0) {
			input_strings[j] = strdup(argv[i]);
			j++;
		} else {
			continue;
		}
	}
	
	search_string(input_strings, input_len, MATCH_OR);	

	return 1;
}
