#include "get_next_line.h"

unsigned long count_fd_size(int fd)
{
    unsigned long ui_count;
    char *str_c;
    unsigned long i_read_res;
    
    ui_count = 10000;
    i_read_res = 1;
    while(i_read_res != 0)
    {
        str_c = (char *)malloc(ui_count);
        i_read_res = read(fd, str_c, ui_count);
       // printf("\n%s\n\nread-res: %d, count %ld\n",str_c, i_read_res, ui_count);
        if (i_read_res < ui_count)
        {
            ui_count = i_read_res;
            break ;
        }
        else
            ui_count += 10000;
        free(str_c);
    }
    free(str_c);
    return (ui_count);
}

char *get_next_line(int fd)
{
    unsigned long ui_len_fd;
    char *str_c;

    ui_len_fd = count_fd_size(fd);
    printf("The len of the file are %ld\n", ui_len_fd);
    str_c = (char *)malloc(ui_len_fd);
    read(fd, str_c, ui_len_fd - 1);
    printf("%s", str_c);
    return (str_c); 
}