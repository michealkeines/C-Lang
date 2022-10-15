#include "./check_file.h"

u_int
check_has_hole(int fd)
{
    printf("Starting to check for hole\n");

    off_t top = lseek(fd, 0, SEEK_CUR);
    off_t total_len = lseek(fd, 0, SEEK_END);
    printf("current after total %lld\n", lseek(fd, 0, SEEK_CUR));
    if (total_len == -1)
        return HOLE_ABSENT;
    
    lseek(fd, top, SEEK_SET);
    printf("current after top set %lld\n", lseek(fd, 0, SEEK_CUR));
    off_t current = 0;

    while (current < total_len) {
        printf("while loop starts\n");
        off_t start = lseek(fd, current, SEEK_HOLE);

        if (current == -1) {
            fprintf(stderr, "lseek failed, ERRO: %d\n", errno);
            return HOLE_ABSENT;
        }
        printf("current start: %lld, total: %lld\n", start, total_len);
        if (current != 0 && start == total_len) {
            return HOLE_PRESENT;
        }

        current = lseek(fd, start, SEEK_DATA);

        if (current == -1) {
            switch (errno) {
                case ENXIO:
                    current = total_len;
                default:
                    fprintf(stderr, "lseek failed in switch, ERRO: %d\n", errno);
                    return HOLE_ABSENT;
            }
        }
        printf("Found Hole: %08llx and %08llx (%lld)\n", start, current, (current - start));
    }
    
    return HOLE_PRESENT;
}
