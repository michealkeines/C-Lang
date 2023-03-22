#include <stdio.h>
#include <iostream>
#include <string>

struct Total {
    int count;
};

struct Points {
    char name[8];
    struct Points *next_point;
};

void insert_points(struct Points *cur, struct Points *next)
{
    cur->next_point = next;
}

// p1 ----- p2  ------ p3

int main()
{
    struct Total test1;

    test1.count = 10;

    struct Points p1;
    struct Points p2;
    struct Points p3;

    std::string myString = "hell1";

    // Copy the string into the array
    for (int i = 0; i < myString.length(); i++) {
        p1.name[i] = myString[i];
    }
    std::string myString2 = "hell2";
    for (int i = 0; i < myString2.length(); i++) {
        p2.name[i] = myString2[i];
    }
    std::string myString3 = "hell3";
    for (int i = 0; i < myString3.length(); i++) {
        p3.name[i] = myString3[i];
    }


    insert_points(&p1, &p2);
    insert_points(&p2, &p3);
    insert_points(&p3, NULL);

    for (struct Points *current = &p1; current->next_point != NULL; current = current->next_point) {
        printf("current: %s, curr: %x next: %x\n", current->name, current, current->next_point);
    }
    return 0;
}