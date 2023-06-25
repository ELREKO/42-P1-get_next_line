#include "get_next_line.h"

static char *ft_read_feedback(int fd, long *ui_read_res)
{
    char *str_c;
    
    str_c = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!str_c)
        return (NULL);
    ft_bzero(str_c, BUFFER_SIZE + 1);
    *ui_read_res = read(fd, str_c, BUFFER_SIZE);
    //printf ("|%s| -- |%ld|\n", str_c, *ui_read_res);
    //Check ok ! 
    return (str_c);
}

static char *ft_copy_togehter(char *temp, char *str_read, char *str_ret)
{
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
        str_ret = temp;
        return (str_ret); 
}

char *ft_feedback_newline(char **str_test, unsigned int ui_pos)
{
    char *str_ret;
    char *str_store;

    str_ret = (char *)malloc(sizeof(char *) * (ui_pos + 1));
    str_store = (char *)malloc(sizeof(char *) * BUFFER_SIZE);
    if (!str_ret || !str_store)
        return (NULL);
    //printf ("*str_test: |%s|--- ui_pos: |%d|\n\n", *str_test, ui_pos);

    ft_bzero(str_ret, ft_strlen(str_ret));
    ft_strncpy(str_ret, *str_test, ui_pos);

    ft_bzero(str_store, ft_strlen(str_store));
    ft_strncpy(str_store, *str_test + ui_pos + 1, (ft_strlen(*str_test) - (ui_pos)));


    //printf("str_ret: |%s| -- str_store: |%s|\n", str_ret, str_store);

    free(*str_test);
    *str_test = (char *)malloc(sizeof(char *) * (ui_pos +1));
    if (!*str_test)
        return (NULL);
    ft_bzero(*str_test, ft_strlen(*str_test));
    ft_strncpy(*str_test, str_ret, ui_pos);

    free(str_ret);

    //printf("*str_test after Change: |%s|", *str_test);

    return (str_store);
}

int ft_check_newline(char *str_test)
{
    unsigned int ui_count;
    ui_count = 0;
    while (str_test[ui_count] != '\0')
    {   
        if (str_test[ui_count]  == '\n')
            return (ui_count);
        ui_count++;
    }
    return (0);
}

static char *ft_compare_together(int fd)
{   
    unsigned int str_store_len;   
    long ui_read_res;
    char *temp;
    char *str_read;
    char *str_ret;
    static char *str_store;

    str_read = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    str_ret = NULL;
    if (!str_read)
        return (NULL);

    if (str_store == NULL)
    {
        str_store = (char *)malloc(sizeof(char) * BUFFER_SIZE);
            if(!str_store)
                return (NULL);
    }
    else
        ft_strncpy(str_ret, str_store, ft_strlen(str_store));

    ft_bzero(str_read, BUFFER_SIZE + 1);
    //printf("i am in here str_store |%s| \n",  str_read);   
    ui_read_res = 1;
    while (ui_read_res != 0 && ui_read_res != -1 && ui_read_res <= BUFFER_SIZE)
    { 
        str_read = ft_read_feedback(fd, &ui_read_res);
        if (ui_read_res == -1)
            return (NULL);
        if (ui_read_res == 0)
        {
            return ("");
        }
        str_store_len = (str_ret != NULL) ? ft_strlen(str_ret) : 0;      
        temp = (char *)malloc((BUFFER_SIZE + str_store_len + 1) * sizeof(char));
        if (!temp) 
        {
            free(str_read);
            return NULL;
        }
        ft_copy_togehter(temp,str_read,str_ret);
        //free(str_ret); // Free the previously allocated memory
        str_ret = temp;
        if (ft_check_newline(str_ret) != 0)
        {
            str_store = ft_feedback_newline(&str_ret, ft_check_newline(str_ret));
            break ;
        }
    }  
    //printf("str_store |%s|\n", str_store); 
    return (str_ret);
}
    
char *get_next_line(int fd)
{
    char *str_ret;
    str_ret = ft_compare_together(fd);
    return (str_ret); 
}