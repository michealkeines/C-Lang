#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

struct Machine {
	int id;
};


struct Person *Person_create(char *name, int age, int height, int weight) {
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

void Person_destroy(struct Person *who) {
	assert(who != NULL);

	free(who->name);
	free(who);
}

void Person_print(struct Person *who) {
	assert(who != NULL);

	printf("Name: %s\n", who->name);
	printf("Age: %d\n", who->age);
	printf("Height: %d\n", who->height);
	printf("Weight: %d\n", who->weight);
}

int main(int argc, char *argv[]) {
	struct Person *micheal = Person_create("Micheal", 23, 181, 60);
	struct Person *kaines = Person_create("Kaines", 24, 180, 60);

	struct Machine test;
	test.id = 10;
	
	printf("%d\n",test.id);

	int t = micheal->age; // pointers can be dereferenced using ->
	int age = (*(micheal)).age; // it can be direclty accessed if we have struct using .(dot)

	printf("a: %d\n",age);

	printf("Micheal is at memory location %p:\n", micheal);
	Person_print(micheal);

	printf("Kaines is at memory location %p:\n", kaines);
	Person_print(kaines);

//	Person_destroy(micheal);
//	Person_destroy(kaines);

//	Person_destroy(NULL);

	return 0;
}
