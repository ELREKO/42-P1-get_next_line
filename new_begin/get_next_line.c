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











long ft_check_Newline(char *str_check)
{
    long l_count;
    l_count = 0;
    while (str_check[l_count] != '\0')
    {   
        if (str_check[l_count]  == '\n')
            return(l_count);
        l_count++;
    }
    return(-1);
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
    return (str_ret);
}


char *get_next_line(int fd)
{
    char *str_ret;
    static char *str_mem;
    long l_read_res;
    int i_check_error;
    long l_len_new;

    i_check_error = 0;

    if (!str_mem)
    {
        if((str_mem = ft_calloc_char(BUFFER_SIZE + 1)) == NULL)
        {
            
            return (NULL);
        }
        if((str_ret = ft_calloc_char(1)) == NULL)
        {   free(str_mem);
            return (NULL);
        }
    }
    else
    {
        if((str_ret = ft_calloc_char(ft_strlen(str_mem) + 1)) == NULL)
            return (NULL);
        ft_strncpy(str_ret,str_mem,ft_strlen(str_mem));
    }
    l_read_res = 1;
    while (l_read_res != 0 && i_check_error == 0)
    {
        if ((str_ret = str_join_read(str_ret, ft_read_feedback(fd, &l_read_res))) == NULL)
            i_check_error = 1;
        if (l_read_res == -1)// || l_read_res == 0)
            i_check_error = 1;  
        if ((l_len_new = ft_check_Newline(str_ret)) != -1)
        {
            ft_strncpy(str_mem, str_ret + l_len_new + 1, ft_strlen(str_ret) - l_len_new );
            ft_strncpy(str_ret, str_ret, l_len_new);
            str_ret[l_len_new + 1] = '\0';
            break ;
        }
    }
    if (i_check_error)
    {
        free(str_mem);
        free(str_ret);
        return (NULL);
    }  
    return (str_ret);
}