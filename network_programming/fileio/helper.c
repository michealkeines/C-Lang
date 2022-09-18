#include "./helper.h"

/*
    convert char to unsigned long
    return u_long
    return 0, if error
*/
u_long 
get_long(char *buff)
{
    return strtol(buff, NULL, 10);
}