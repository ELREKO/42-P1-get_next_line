#include "get_next_line.h"

int main(void) 
{
    int fd;
    char *str_read;

    fd = open("Test.txt", O_RDONLY);
    if (fd < 0) {
        perror("r1");
        exit(1);
    }
int i = -1;
while (++i < 7)
{
    str_read = get_next_line(fd);
    printf("%s", str_read);
    free(str_read);
}
    int result = close(fd);
    if (result < 0) {
        perror("Error closing file");
        exit(1);
    }
    return (0);
}
