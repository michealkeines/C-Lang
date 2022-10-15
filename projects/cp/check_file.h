#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <stdio.h>

#define HOLE_PRESENT 1
#define HOLE_ABSENT 0

u_int check_has_hole(int);