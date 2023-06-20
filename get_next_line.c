#include "get_next_line.h"
// This function i does not need anymore 
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
  //  unsigned long ui_len_fd;
    char *str_c;
    static char *str_store = NULL;
    char *temp;
    int i_read_res;
    size_t str_store_len;

    str_c = (char *)malloc(BUFFER_SIZE);
    if (!str_c)
       return (NULL);
    i_read_res = 1;
    while (i_read_res != 0 && i_read_res != -1 && i_read_res <= BUFFER_SIZE)
    { 
        ft_bzero(str_c, BUFFER_SIZE);
        i_read_res = read(fd, str_c, BUFFER_SIZE);
        if (i_read_res == -1)
            return (NULL);
        if (i_read_res == 0)
            break;
        str_store_len = (str_store != NULL) ? ft_strlen(str_store) : 0;
        temp = (char *)malloc((BUFFER_SIZE + str_store_len) * sizeof(char));
    //        printf("|%s| -- |%d| -- |%s|\n", str_c, i_read_res, str_store);
        if (!temp) 
        {
            free(str_c);
            return NULL;
        }
        if (str_store)
        {
            ft_strcpy(temp, str_store);
            ft_strcat(temp,str_c);
            free(str_store);
        }
        else
        {
            strcat(temp,str_c);
        }
        str_store = temp;

        printf("|%s| -- |%d| -- |%s| -- |%s|\n", str_c, i_read_res, str_store, temp);  
        
    }
    free(str_c);
 
    return (str_store); 
}