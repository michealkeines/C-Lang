#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    if (argc <= 2 || argc >= 5 || strcmp("--help", argv[1]) == 0 ) {
        fprintf(stderr, "Usage: %s <filename> <num of bytes> <append only>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *file_name;
    size_t len;
    mode_t current_mode = O_WRONLY | O_CREAT;


    file_name = argv[1];
    sscanf(argv[2], "%zu", &len);

    char *buff = malloc(len);

    if (buff != NULL) {
        memset(buff, 65, len - 3);
        buff[len - 2] = '\n';
        buff[len - 1] = '\0';
    } else {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }

    int fd;
    int perms = S_IREAD | S_IWRITE | S_IRGRP | S_IWGRP;

    if (argc != 4) {
        current_mode |= O_APPEND;
        printf("Append Mode\n");
    }

    fd = open(file_name, current_mode, perms);

    if (fd == -1) {
        fprintf(stderr, "Couldn't open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    if (argc == 4) {
        off_t curr_off = lseek(fd, 0, SEEK_END);
        if (curr_off == -1) {
            fprintf(stderr, "lseek failed to get\n");
            exit(EXIT_FAILURE);
        }
        off_t seting = lseek(fd, curr_off, SEEK_SET);
        if(seting == -1) {
            fprintf(stderr, "lseek failed to set\n");
            exit(EXIT_FAILURE);
        }
    }

    size_t bytes_written = write(fd, buff, len);

    if (bytes_written == -1) {
        fprintf(stderr, "write failed\n");
        exit(EXIT_FAILURE);
    }

    if (bytes_written != len) {
        fprintf(stderr, "not written completely\n");
        exit(EXIT_FAILURE);
    }

    printf("Total %zu bytes written\n", bytes_written);

    exit(EXIT_SUCCESS);
}