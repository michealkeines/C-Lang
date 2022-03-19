#include <stdio.h>
#include <string.h>
#include "../dbg.h"

int normal_copy(char * from, char * to, int count) {
	int i = 0;
	for (i = 0; i < count; i++) {
		to[i] = from[i];
	}
	return i;
}

int duffs_device(char * from, char * to, int count) {
	{
		int n = (count + 7) / 8;
		// loop unrolling technique
		// if we have count value that is not divible by 8, we take module and start from that case, rest of the one will who through every case
		switch (count % 8) {
			case 0:
			printf("current count: %d\n", count);
				do {
					*to++ = *from++;
			printf("8 %c ->  %c\n",*to, *from);
					case 7:
			printf("7 %c ->  %c\n",*to, *from);
					*to++ = *from++;
					case 6:
			printf("6 %c ->  %c\n",*to, *from);
					*to++ = *from++;
					case 5:
			printf("current count: %d\n", n);
			printf("5 %c ->  %c\n",*to, *from);
					*to++ = *from++;
					case 4:
			printf("4 %c ->  %c\n",*to, *from);
					*to++ = *from++;
					case 3:
			printf("3 %c ->  %c\n",*to, *from);
					*to++ = *from++;
					case 2:
			printf("2 %c ->  %c\n",*to, *from);
					*to++ = *from++;
					case 1:
			printf("1 %c ->  %c\n",*to, *from);
					*to++ = *from++;
				} while (--n > 0);

		}
	}
	return count;
}

int zeds_device(char * from, char * to, int count) {
	{
		int n = (count + 7) / 8;
		switch (count % 8) {
			case 0:
		again:  *to++ = *from++;
			printf("0 %c ->  %c\n",*to, *from);
			case 7:
			*to++ = *from++;
			printf("7 %c ->  %c\n",*to, *from);
			case 6:
			*to++ = *from++;
			printf("6 %c ->  %c\n",*to, *from);
			case 5:
			*to++ = *from++;
			printf("5 %c ->  %c\n",*to, *from);
			case 4:
			*to++ = *from++;
			printf("4 %c ->  %c\n",*to, *from);
			case 3:
			*to++ = *from++;
			printf("3 %c ->  %c\n",*to, *from);
			case 2:
			*to++ = *from++;
			printf("2 %c ->  %c\n",*to, *from);
			case 1:
			*to++ = *from++;
			printf("1 %c ->  %c\n",*to, *from);
			if (--n > 0) {
				goto again;
			}
		}
	}
	return count;
}

int valid_copy(char * data, int count, char expects) {
	int i = 0;
	for (i = 0; i < count; i++) {
		if (data[i] != expects) {
			log_err("[%d] %c != %c", i, data[i], expects);
			return 0;
		}
	}
	return 1;
}

int main(int argc, char * argv[]) {
	char from[1000] = {'a'};
	char to[1000] = {'c'};

	int rc = 0;

	memset(from, 'x', 1000);
	memset(to, 'y', 1000);
	check(valid_copy(to, 997, 'y'), "Not initialized right.");

	rc = normal_copy(from, to,  997);
//	check(rc == 1000, "normal copy failed %d",rc);
//	check(valid_copy(to, 997, 'x'), "Normal copy failed.");

	memset(to, 'y', 1000);

	rc = duffs_device(from, to, 997);
//	check(rc == 1000, "Duff's device failed: %d", rc);
//	check(valid_copy(to, 1000, 'x'), "Duffs device failed");

	memset(to, 'y', 1000);

	rc  = zeds_device(from, to, 997);
//	check(rc == 1000, "Zeds device failed: %d", rc);
//	check(valid_copy(to, 1000, 'x'), "zeds device failed");

	return 0;
error:
	return 1;
}




