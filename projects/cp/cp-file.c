#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

u_int check_has_hole(int);

int 
main(int argc, char *argv[])
{
    if ((argc == 2 || argc > 3) && (strcmp(argv[1], "--help") || strcmp(argv[1], "-h"))) {
        help:
            fprintf(stderr, "Usage: %s <source file> <destination file>\n");
            exit(EXIT_FAILURE);
    }

    char *source = argv[1];
    char *destination = argv[2];

    int fd;

    mode_t open_mode = O_RDONLY;

    fd = open(source, open_mode);

    if (fd == -1) {
        fprintf(stderr, "Couldn't open %s, Error: %d\n", source, errno);
        exit(EXIT_FAILURE);
    }

    u_int has_hole = check_file_hole(fd);

    exit(EXIT_SUCCESS);
}