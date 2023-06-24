# include "get_next_line.h"

size_t ft_strlen(char * str)
{
    size_t ui_count;
    
    ui_count = 0;
    if (!str)
        return (0);
    while(*str++ != '\0')
        ui_count++;
    return (ui_count);
}

char *ft_strncpy(char *dest, const char *src, unsigned int size)
{
    unsigned int ui_count;

    ui_count = 0;
    while (src[ui_count] != '\0' && ui_count <= size )
    {
        dest[ui_count] = src[ui_count];
        ui_count++;
    }
    dest[ui_count] = '\0';
    return (dest);
}

char *ft_strcat(char *dest, const char *src)
{
    size_t ui_len_src;
    size_t ui_count;

    ui_count = 0;  
    ui_len_src = ft_strlen(dest);
    while (src[ui_count] != '\0')
    {
        dest[ui_len_src + ui_count] = src[ui_count];
        ui_count++;
    }
    dest[ui_len_src + ui_count] = '\0';
    return (dest);
}

void ft_bzero(void *str, size_t ui_len)
{
    unsigned char *mem;
    size_t ui_count;

    mem = (unsigned char *)str;
    ui_count = 0;
    while(ui_count < ui_len)
    {
        mem[ui_count] = '\0';
        ui_count++;
    }
    str = mem;
}
