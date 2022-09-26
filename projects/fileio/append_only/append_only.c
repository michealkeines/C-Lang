#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    int fd;
    char *name = "file.txt";

    mode_t open_mode = O_RDWR | O_APPEND;

    int flags = S_IRUSR | S_IRGRP | S_IRGRP | S_IRGRP;

    fd = open(name, open_mode, flags);

    if (fd == -1) {
        fprintf(stderr, "Couldn't open %s file\n", name);
        exit(EXIT_FAILURE);
    }

    off_t top = lseek(fd, 0, SEEK_SET);

    if (top == -1) {
        fprintf(stderr, "Couldn't set seek to top\n");
        exit(EXIT_FAILURE);
    }
    printf("Current offset %lld\n", top);

    char *buff = argv[1];
    size_t len = strlen(buff);
    if (len <= 2) {
        fprintf(stderr, "nothing to write\n");
        exit(EXIT_FAILURE);
    }

    buff[len - 2] = '\n';
    buff[len - 1] = '\0';

    size_t bytes_written = write(fd, buff, len);

    if (bytes_written  == -1) {
        fprintf(stderr, "Not written\n");
        exit(EXIT_FAILURE);
    }

    if (bytes_written != len) {
        fprintf(stderr, "not fully written\n");
        exit(EXIT_FAILURE);
    }

    printf("Written %zu bytes to %s\n", bytes_written, name);

    exit(EXIT_SUCCESS);
}
