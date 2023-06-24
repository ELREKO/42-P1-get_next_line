#include "get_next_line.h"

static char *ft_read_feedback(int fd, long *ui_read_res)
{
    char *str_c;
    
    str_c = (char *)malloc(BUFFER_SIZE);
    if (!str_c)
        return (NULL);
    ft_bzero(str_c, BUFFER_SIZE);
    *ui_read_res = read(fd, str_c, BUFFER_SIZE);
    return (str_c);
}

static char *ft_copy_togehter(char *temp, char *str_read, char *str_ret)
{
        if (str_ret)
        {
            ft_strcpy(temp, str_ret);
            ft_strcat(temp,str_read);
            free(str_ret);
        }
        else
        {
            strcat(temp,str_read);
        }
        str_ret = temp;
        return (str_ret); 
}

static char *ft_compare_together(int fd)
{   
    unsigned int str_store_len;   
    long ui_read_res;
    char *temp;
    char *str_read;
    char *str_ret;
    
    ui_read_res = 1;
    while (ui_read_res != 0 && ui_read_res != -1 && ui_read_res <= BUFFER_SIZE)
    { 
        str_read = ft_read_feedback(fd, &ui_read_res);
        if (ui_read_res == -1)
            return (NULL);
        if (ui_read_res == 0)
            break ;
        str_store_len = (str_ret != NULL) ? ft_strlen(str_ret) : 0;
        temp = (char *)malloc((BUFFER_SIZE + str_store_len) * sizeof(char));
        if (!temp) 
        {
            free(str_read);
            return NULL;
        }
        str_ret = ft_copy_togehter(temp,str_read,str_ret);
    }
    //free(str_read);
    return (str_ret);
}

char *get_next_line(int fd)
{
    char *str_ret;
    str_ret = ft_compare_together(fd);
    return (str_ret); 
}