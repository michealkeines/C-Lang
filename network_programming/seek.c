#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        fprintf(stderr, "Input not supplied properly.\n");
        exit(-1);
    }

    int fd;

    fd = open("./test.txt", O_RDONLY);

    if (fd == -1)
    {
        fprintf(stderr, "Couldn't open File.");
        exit(-1);
    }

    off_t new_off;

    new_off = lseek(fd, atoi(argv[1]), SEEK_CUR);

    char buff[50];

    int res = read(fd, buff, 2);

    if( res == -1)
    {
        fprintf(stderr, "read failed");
        exit(-1);
    }
    if (res < 50) 
    {
        buff[res] = '\0';
    }
    else
    {
        fprintf(stderr, "overflow detected");
    }

    printf("read value: %s\n", buff);

}