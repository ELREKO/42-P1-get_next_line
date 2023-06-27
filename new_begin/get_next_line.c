#include "get_next_line.h"

static char *ft_read_feedback(int fd, long *l_read_res)
{
    char *str_c;
    
    str_c = (char *)malloc(BUFFER_SIZE + 1);
    if (!str_c)
        return (NULL);
    ft_bzero(str_c, BUFFER_SIZE + 1);
    *l_read_res = read(fd, str_c, BUFFER_SIZE);
    return (str_c);
}











unsigned int ft_check_Newline(char *str_check)//, char **str_store)
{
    unsigned int ui_count;
    char *mem; 
    if ((mem = ft_calloc_char(ft_strlen(str_check) + 1)) == NULL)
        return (-1);
    ui_count = 0;
    // while (str_check[i_count] != '\0')
    // {
    //     //printf("%c\n", str_check[i_count]);
    //     mem[i_count] = str_check[i_count];
    //     if (str_check[i_count] == 10)
    //     {
    //         printf("\n\n Gefundne \n\n");
    //         return (0);
    //     }
    //     i_count++;
    // }

    while (str_check[ui_count] != '\0')
    {   
        if (str_check[ui_count]  == '\n')
            return (ui_count);
        ui_count++;
    }
    free(mem);
    return (1);
}

char *str_join_read(char *str_old, char *str_read)
{
    char *str_ret;
    long l_count_st_old;
    long l_count_read;

    if((str_ret = ft_calloc_char(ft_strlen(str_old) + ft_strlen(str_read) + 1)) == NULL)
        return (NULL);
    //printf("%s",str_read);
    l_count_st_old = 0;
    while (str_old[l_count_st_old] != '\0')
    {
        str_ret[l_count_st_old] = str_old[l_count_st_old];
        l_count_st_old++;
    }
    l_count_read = 0;
    while (str_read[l_count_read] != '\0')
    {
        str_ret[l_count_st_old + l_count_read] = str_read[l_count_read];
        l_count_read++;
    }
    free(str_read);
    free(str_old);
    // if((str_old = ft_calloc_char(ft_strlen(str_ret) + 1)) == NULL)
    // {   
    //     free(str_ret);
    //     return (NULL);
    // }
    // str_old=strdup(str_ret);
    // free(str_ret);
    // printf("%s\n", str_old);
   return (str_ret);
}


char *get_next_line(int fd)
{
    char *str_ret;
    char *str_mem;
    //static char *str_mem;
    long l_read_res;
    int i_check_error;

    i_check_error = 0;
    if((str_ret = ft_calloc_char(1)) == NULL)
        return (NULL);

    
    if((str_mem = ft_calloc_char(BUFFER_SIZE + 1)) == NULL)
    {
        free(str_ret);
        return (NULL);
    }
    l_read_res = 1;
    while (l_read_res != 0)
    {
        str_ret = str_join_read(str_ret, ft_read_feedback(fd, &l_read_res));
        if ((str_ret) == NULL)
            i_check_error = 1;
        if (l_read_res == -1)
            i_check_error = 1;  
    }
    printf("%s", str_ret);
    if (i_check_error)
    {
        free(str_mem);
        free(str_ret);
        return (NULL);
    }  
    free(str_mem);
    return (str_ret);
}