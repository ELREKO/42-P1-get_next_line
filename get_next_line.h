#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
    #define BUFFER_SIZE 6
#endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

char *get_next_line(int fd);
//helpers
size_t ft_strlen(char * str);
char *ft_strncpy(char *dest, const char *src, unsigned int size);
char *ft_strcat(char *dest, const char *src);
void ft_bzero(void *str, size_t ui_len);

#endif