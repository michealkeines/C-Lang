#include <stdio.h>
#include <stdint.h>
#include "./types.h"

extern uint8_t find_max(vector_t *, vector_t *);

int main()
{
    color_t sample_color = {
        .blue = 112,
        .red = 115,
        .green = 110,
        .orange = 167,
        .yellow = 88
    };

    vector_t sample_location = {
        .x_axis = 2,
        .y_axis = 4
    };

    vector_t sample_location2 = {
        .x_axis = 1,
        .y_axis = 3
    };

    sample_t sample = {
        .first = 'a',
        .second = 'b',
        .third = 'c',
        .fourth = 145
    };

    printf("size of color: %d, val: %d, var: %d\n", sizeof(color_t), sizeof(uint32_t), sizeof(sample_color));
    printf("size of vector: %d, val: %d, var: %d\n", sizeof(vector_t), sizeof(int64_t), sizeof(sample_location));
    printf("size of sample: %d, var: %d\n", sizeof(sample_t), sizeof(sample));

    uint8_t check = find_max(&sample_location, &sample_location2);

    if (check == 1)
    {
        printf("a is greater\n");
    }

    return 0;
}