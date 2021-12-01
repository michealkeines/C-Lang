#include <stdio.h>

int main(int argc, char *argv[])
{
	int age = 10;
	int height = -72;

	printf("I am %d years old.\n",age);
	printf("I am %i inches tall.\n",height); // i represents unsinged

	char ch = 'M';
	printf("My Initial is %c\n", ch); // c represents charcters

	int temperature = 23;
	int f = -33;
	printf("Current Temperature is %u.\n",temperature); // u represents unsigned values
	printf("Test %u.\n",f);

	float drag = 1.45;

	printf("Time drag is %f.\n",drag); // f represents floating point values
	printf("Test %d.\n",drag);

	char c = 'a';
	printf("octal %o.\n",c); // o represents octal values

	char k = 'A';
	printf("%x is presented as A\n",k); // x hexadecimal values
	
	char name[] = "Micheal Keines";
	printf("I am %s\n",name);  // s String values

	int current_location = 10;
	printf("We are at %p\n", &current_location);

	return 0;
}
