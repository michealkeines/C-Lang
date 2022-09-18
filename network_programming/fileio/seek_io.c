#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "./helper.h"

int
main(int argc, char **argv)
{
    size_t len;
    off_t offset;
    int fd, ap, j;
    char *buff;
    ssize_t num_read, num_written;

    if (argc < 3 || strcmp(argv[1], "--help") == 0) {
        fprintf(stderr, "Usage: %s <input file> <r{lenght} | R{length} | w{string} | s{offset}>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // Read-Write and Create
    int mode = O_RDWR | O_CREAT;
    // rw-rw-rw-, user, group, others
    int flags = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

    fd = open(argv[1], mode, flags);

    if (fd == -1) {
        fprintf(stderr, "Err-Code: %d", errno);
        exit(EXIT_FAILURE);
    }

    for (ap = 2; ap < argc; ap++) {
        switch (argv[ap][0]) {
            case 'r':
            case 'R':
                len = get_long(&argv[ap][1]);
                
                buff = (char *) malloc(len);
                if (buff == NULL) {
                    fprintf(stderr, "malloc failed");
                    exit(EXIT_FAILURE);
                }

                num_read = read(fd, buff, len);
                if (num_read == -1) {
                    fprintf(stderr, "read failed");
                    exit(EXIT_FAILURE);
                }

                if (num_read == 0) {
                    printf("%s: end-of-file\n", argv[ap]);
                } else {
                    printf("%s: ", argv[ap]);
                    for (j = 0; j < num_read; j++) {
                        if (argv[ap][0] == 'r') {
                            printf("%c", isprint((unsigned char) buff[j]) ? buff[j] : '?');
                        } else {
                            printf("%02x", (unsigned int) buff[j]);
                        }
                    }
                    printf("\n");
                }
                free(buff);
                break;
            case 'w':
                num_written = write(fd, &argv[ap][1], strlen(&argv[ap][1]));
                if (num_written == -1) {
                    fprintf(stderr, "write failed");
                    exit(EXIT_FAILURE);
                }
                printf("%s: write succeeded\n", argv[ap]);
                break;

            case 's':
                offset = get_long(&argv[ap][1]);
                if (lseek(fd, offset, SEEK_SET) == -1) {
                    fprintf(stderr, "seek failed");
                    exit(EXIT_FAILURE);
                };
                printf("%s: seek succeeded\n", argv[ap]);
                break;

            default:
                fprintf(stderr, "Arguments must start with [rRws]: %s\n", argv[ap]);
                exit(EXIT_FAILURE);
        }
    }
    exit(EXIT_SUCCESS);
}