#include "./types.h"

uint8_t find_max(vector_t *a, vector_t *b)
{
    if ((a->x_axis > b->x_axis) && a->y_axis > b->y_axis)
    {
        return 1;
    }

    return 0;
}