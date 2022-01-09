#include <stdio.h>
#include <string.h>

int main() {
	char buff[1024];

	memset(buff, '\0', sizeof(buff)); // memset is used to copy a char to buffer as user specified times, in this case \0 will be copied in every byte of the buffer

	fprintf(stdout, "Going to set full buffering on\n");
	setvbuf(stdout, buff, _IOFBF, 1024);

	fprintf(stdout, "This is for testing purpose only.\n");
	fprintf(stdout, "Please dont try this at home\n");
	fflush(stdout); // once a fflush is calles, rest of the fprintf will only be printed when the code reaches the end
	
	fprintf(stdout, "i dont know\n");
	fprintf(stdout, "stay safe.\n");

	sleep(3);

	return 0;
}
