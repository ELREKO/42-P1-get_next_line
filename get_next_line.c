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
static char *ft_copy_togehter(char *str_read, char *str_ret)
{
        unsigned int str_len;
        char *temp;

        str_len = (str_ret != NULL) ? ft_strlen(str_ret) : 0;
        temp = (char *)malloc((BUFFER_SIZE + str_len + 1) * sizeof(char));
        if (!temp) 
            return NULL;
        if (str_ret)
        {
            ft_strncpy(temp, str_ret, ft_strlen(str_ret));
            ft_strcat(temp,str_read);
            free(str_ret);
        }
        else
        {
            strcat(temp,str_read);
        }
        str_ret = (char *)malloc((BUFFER_SIZE + str_len + 1) * sizeof(char));
        if (!str_ret) 
            return NULL;
        ft_strncpy(str_ret, temp, ft_strlen(temp));
        free(temp);
        return (str_ret); 
}












unsigned int  ft_check_newline(char *str_test)
{  
    int ui_count;
 
    ui_count = 0;
    while (str_test[ui_count] != '\0')
    {   
        if (str_test[ui_count]  == '\n')
            return (ui_count);
        ui_count++;
    }
    return (0);
}





int ft_feedback_newline(char **str_test, char **str_store)
{
    char *str_ret;
    unsigned int ui_pos;

    str_ret = *str_test;
    if ((ui_pos = ft_check_newline(str_ret)))
    {
        str_ret = (char *)malloc(sizeof(char *) * (ui_pos + 1));
        if (!str_ret)
            return (-1);
        ft_bzero(str_ret, ft_strlen(str_ret));
        ft_strncpy(str_ret, *str_test, ui_pos);
        ft_strncpy(*str_store, *str_test + ui_pos + 1, (ft_strlen(*str_test) - (ui_pos)));
        free(*str_test);
        *str_test = (char *)malloc(sizeof(char *) * (ui_pos +1));
        if (!*str_test)
            return (-1);
        ft_bzero(*str_test, ft_strlen(*str_test));
        ft_strncpy(*str_test, str_ret, ui_pos);
        free(str_ret);
        return (1);
    }
    return (0);
}









char *get_next_line(int fd)
{   
    long ui_read_res;
    char *str_read;
    char *str_ret;
    static char *str_store;

    if (str_store == NULL)
    {
        str_store = (char *)malloc(sizeof(char *) * BUFFER_SIZE);
        if(!str_store)
            return (NULL);
    }
    else
        ft_strncpy(str_ret, str_store, ft_strlen(str_store)); 
    ui_read_res = 1;
    while (ui_read_res != 0 && ui_read_res != -1 && ui_read_res <= BUFFER_SIZE)
    { 
        str_read = ft_read_feedback(fd, &ui_read_res);
        printf("READ: ui_read_res|%ld| -- str_read|%s|\n", ui_read_res, str_read);
        if (ui_read_res == -1)
            return (NULL);
        if (ui_read_res == 0)
            return ("");
        str_ret = ft_copy_togehter(str_read,str_ret);
        if (ft_feedback_newline(&str_ret, &str_store))
            break ;
    }
    free(str_read);
    return (str_ret);
}