#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef uint8_t (*filter)(int64_t, int64_t);

void swap(int64_t *a, int64_t* b)
{
    int64_t temp = *b;
    *b = *a;
    *a = temp;
}

uint8_t asc(int64_t a, int64_t b)
{
    return a > b ? 1 : 0;
}

uint8_t desc(int64_t a, int64_t b)
{
    return a < b ? 1 : 0;
}

void bubble_sort(int64_t *arr, size_t size, filter filter_ptr)
{
    for (uint64_t i = 0; i < size; i++)
    {
        for (uint64_t j = 0; j < (size - 1); j++)
        {
            if (filter_ptr(arr[j], arr[j + 1]) == 1)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

uint64_t get_split_array(char *input_str, char *separator, char **output)
{
    char *token;

    uint64_t count = 0;

    token = strtok(input_str, separator);

    while (token != NULL)
    {
#ifdef DEBUG
        printf("token: %s\n", token);
#endif
        output[count] = token;

        count++;
        token = strtok(NULL, separator);
    }

    return count;
}

int main(int argc, char **argv)
{
    if (argc < 2) 
    {
        fprintf(stderr, "Usage: sort numbers seperated with , and optional the asc or desc\n");
        fprintf(stderr, "\t./sort '5, 9, 2, 1, 8, 3' asc\n");
        exit(1);
    }

    char *input_chars = argv[1];

    filter func_ptr = NULL;
    func_ptr = asc;

    if (argc == 3)
    {
        if (strcmp(input_chars, "desc"))
        {
            func_ptr = desc;
        }
    }

    char *output[256];
    char sep[2] = {' ', ','};

    uint64_t count = get_split_array(input_chars, sep, output);

#ifdef DEBUG
    printf("count: %d\n", count);
#endif

    int64_t array[count];

    
    for (uint16_t i = 0; i < count; i++)
    {
#ifdef DEBUG
        printf("%s, ", output[i]);
#endif
        array[i] = (int64_t) atoi(output[i]);
    }
    printf("\n");


    bubble_sort(array, (size_t) count, func_ptr);

    printf("sorted: ");

    for (uint16_t i = 0; i < count; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");

    return 0;
}