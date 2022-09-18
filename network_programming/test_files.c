#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <unistd.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc, char *argv[]) {
    int input_fd, output_fd, open_flags;
    mode_t file_perms;
    int num_read;

    char buf[BUF_SIZE];

    if (argc != 3 || strcmp(argv[1], "--help") == 0) {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        exit(-1);
    }

    input_fd = open(argv[1], O_RDONLY);

    if (input_fd == -1) {
        printf("opening file %s", argv[1]);
        exit(-1);
    }

    open_flags = O_CREAT | O_WRONLY | O_TRUNC;
    file_perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | 
                 S_IROTH | S_IWOTH;
    
    output_fd = open(argv[2], open_flags, file_perms);

    if (output_fd == -1) printf("opening file %s", argv[2]);

    while ((num_read = read(input_fd, buf, BUF_SIZE)) > 0) {
        if (write(output_fd, buf, num_read) != num_read) {
            printf("Couldn't write whole buffer");
            exit(-4);
        }
    }

    if (num_read == -1) exit(-2);

    if (close(input_fd) == -1) exit(-3);
    if (close(output_fd) == -1) exit(-4);

    exit(0);
}