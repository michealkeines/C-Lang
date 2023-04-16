#include <stdio.h>
#include <stdint.h>

typedef struct {
  char first;
  char second;
  char third;
  short fourth;
} sample_t;

typedef struct __attribute__((__packed__)) {
    uint32_t red;
    uint32_t green;
    uint32_t blue;
    uint32_t orange;
    uint32_t yellow;
} color_t;

typedef struct {
    int64_t x_axis;
    int64_t y_axis;
} vector_t;

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

    sample_t sample = {
        .first = 'a',
        .second = 'b',
        .third = 'c',
        .fourth = 145
    };

    printf("size of color: %d, val: %d, var: %d\n", sizeof(color_t), sizeof(uint32_t), sizeof(sample_color));
    printf("size of vector: %d, val: %d, var: %d\n", sizeof(vector_t), sizeof(int64_t), sizeof(sample_location));
    printf("size of sample: %d, var: %d\n", sizeof(sample_t), sizeof(sample));

}