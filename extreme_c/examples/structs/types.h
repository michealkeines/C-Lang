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