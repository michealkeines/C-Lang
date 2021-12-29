#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t pid;

	pid = fork();
	if (pid == 0) {
		printf("ss\n");
	
	}
//	if (pid < 0) {
//		fprintf(stderr, "Fork failed");
//		exit(-1);
//	}
//	else if (pid == 0) {
//		execlp("/bin/ls", "ls", NULL);
//		printf("sdfsf");
//	}
	else {
		wait(NULL);
		printf("Child complete");
		exit(0);
	}

}
