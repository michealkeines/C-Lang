#include <stdio.h>
#include <stdint.h>
#include <string.h>

//#define MAX_VALUE 10
#define MIN_VALUE 1

#ifndef OUTER
#define OUTER "from outer default"
#endif

#define check(a, b) a > b

#define init_command(name) \
    char name ## _cmd[256] = ""; \
    strcpy(name ## _cmd, #name);

#define get_command_name(name) name ## _cmd

#define log_error(format, ...) \
    fprintf(stdout, format, __VA_ARGS__)

#define loop_3(c, ...) \
    printf("%s\n", #c);

#define loop_2(b, ...) \
    printf("%s\n", #b); \
    loop_3(__VA_ARGS__)

#define loop_1(a, ...) \
    printf("%s\n", #a); \
    loop_2(__VA_ARGS__)

#define loop(...) \
    loop_1(__VA_ARGS__)

int main()
{
    uint32_t a = 12;
    uint32_t b = 5;

    if (check(a,b)) 
    {
#ifdef MAX_VALUE
        printf("MAX: %d, MIN: %d\n", MAX_VALUE, MIN_VALUE);
#else
        printf("not defined\n");
#endif
    }

#ifdef init_command
    init_command(copy)
    init_command(paste)

    log_error("current command: %s\n", get_command_name(copy));
    log_error("current command: %s\n", get_command_name(paste));

#else
    printf("command not defined\n");
#endif

#ifdef loop
    loop(value1 value2 value3);
    loop(value1, value2, value3);
    loop(value1, value2, value3, value4, value5);
    loop("test1", "test2" "dgfdg", "tet3");
#else
    printf("loop not defined");
#endif

#ifdef INPUT
    printf("input: %s\n", INPUT);
#else
    printf("input is not defined\n");
#endif

    printf("outer: %s\n", OUTER);

    return 0;
}