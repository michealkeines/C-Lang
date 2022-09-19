#include <fcntl.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define INPUT_MAX 512

enum mode {
    replace,
    append
};

int main(int argc, char *argv[]) {
    // Default mode overwrites the input file
    enum mode current_mode = replace;
    char *filename = NULL;
    if (argc == 2) {
        filename = argv[1];
    } else if (argc > 2) {
        int opt;
        while ((opt = getopt(argc, argv, "a:")) != -1) {
            switch (opt) {
                case 'a':
                    current_mode = append;
                    filename = optarg;
                    break;
                default:
                    fprintf(stderr, "Usage: %s [-a] filename\n", argv[0]);
                    exit(EXIT_FAILURE);
            }
        }
    }

    // printf("Current mode: %d\n", current_mode);

    if (filename == NULL) {
        fprintf(stderr, "Input File name not provided\n");
        exit(EXIT_FAILURE);
    }

    // printf("Input file name: %s\n", filename);

    int user_input_fd;
    int file_mode = O_RDWR | O_CREAT | O_TRUNC;

    if (current_mode == append) {
        file_mode = O_RDWR | O_APPEND;
    }
    
    int perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWGRP;

    user_input_fd = open(filename, file_mode, perms);

    if (user_input_fd == -1) {
        fprintf(stderr, "Couldn't open %s, ERROR: %d\n", filename, errno);
        exit(EXIT_FAILURE);
    }

    char buff[INPUT_MAX];
    ssize_t std_input_len;

    std_input_len = read(0, buff, INPUT_MAX - 1);

    if (std_input_len == -1) {
        fprintf(stderr, "Couldn't read input from user, ERROR: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    ssize_t input_written_len;

    input_written_len = write(user_input_fd, buff, std_input_len);

    if (input_written_len == -1 || input_written_len != std_input_len) {
        fprintf(stderr, "Write to file %s failed, ERROR: %d\n", filename, errno);
        exit(EXIT_FAILURE);
    }

    ssize_t stdout_written_len;

    stdout_written_len = write(1, buff, std_input_len);

    if (stdout_written_len == -1 || stdout_written_len != std_input_len) {
        fprintf(stderr, "Write to stdout failed, ERROR: %d\n", errno);
        exit(EXIT_FAILURE);
    }
    
    exit(EXIT_SUCCESS);
}


