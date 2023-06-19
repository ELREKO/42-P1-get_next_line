# include "get_next_line.h"
  
int main(void)
{
    int fd;
    char *str_read;
  
    fd = open("foo.txt", O_RDONLY);
    if (fd < 0) {
        perror("r1");
        exit(1);
    }
    str_read = get_next_line(fd);
    printf("%s", str_read);

    return (0);
}
