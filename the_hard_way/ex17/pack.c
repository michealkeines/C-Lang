#include <stdio.h>

struct test {
	char * buff; // 8 bytes
	char mode;   // 1 byte
	long id;      // 8 bytes
};


int main() {
	struct test a;
	printf("size: %d\n",sizeof(a));
	printf("size: %d\n",sizeof(a.buff));
	printf("size: %d\n",sizeof(a.mode));
	printf("size: %d\n",sizeof(a.id));

	return 0;
}
