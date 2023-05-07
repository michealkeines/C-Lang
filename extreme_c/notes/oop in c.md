we only have imlicit encapsulation in c

 implicit encapsulation, classes do exist, but they are implicit and known only to the programmer.

```c
#ifndef EXTREME_C_EXAMPLES_CHAPTER_6_1_H
#define EXTREME_C_EXAMPLES_CHAPTER_6_1_H
// This structure keeps all the attributes
// related to a car object
typedef struct {
  char name[32];
  double speed;
  double fuel;
} car_t;
// These function declarations are 
// the behaviors of a car object
void car_construct(car_t*, const char*);
void car_destruct(car_t*);
void car_accelerate(car_t*);
void car_brake(car_t*);
void car_refuel(car_t*, double);
#endif
```

we can write the functoin outside

