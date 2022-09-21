#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

#define HOLE_PRESENT 1
#define HOLE_ABSENT 0

u_int
check_file_hole(int fd)
{
    off_t total_len = lseek(fd, 0, SEEK_END);

    if (total_len == -1)
        return HOLE_ABSENT;

    off_t current = 0;

    while (current < total_len) {
        off_t start = lseek(fd, current, SEEK_HOLE);

        if (current == -1) {
            return HOLE_ABSENT;
        }

        if (current != 0 && start == total_len) {
            return HOLE_PRESENT;
        }

        current = lseek(fd, start, SEEK_DATA);

        if (current == -1) {
            switch (errno) {
                case ENXIO:
                    current = total_len;
                default:
                    return HOLE_ABSENT;
            }
        }
        printf("Found Hole: %08x and %08x (%d)\n", start, current, (current - start));
    }
    
    return HOLE_PRESENT;
}
