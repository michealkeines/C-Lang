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

    mode_t open_mode = O_APPEND;

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

    char *buff = "This will be appended hopefully\n";

    size_t bytes_written = write(fd, buff, sizeof(buff));

    if (bytes_written  == -1) {
        fprintf(stderr, "Not written\n");
        exit(EXIT_FAILURE);
    }

    if (bytes_written != sizeof(buff)) {
        fprintf(stderr, "not fully written\n");
        exit(EXIT_FAILURE);
    }

    printf("Written %zu bytes to %s\n", bytes_written, name);

    exit(EXIT_SUCCESS);
}
