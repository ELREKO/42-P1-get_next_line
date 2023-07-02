/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:16:16 by rkost             #+#    #+#             */
/*   Updated: 2023/06/29 13:18:49 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_join_read(char *str_old, char *str_read)
{
	char	*str_ret;
	size_t	l_count_old;
	size_t	l_count_read;
    //printf("\n----In function join---\n");
	str_ret = ft_calloc_char(ft_strlen(str_old) + ft_strlen(str_read) + 1);
	if(!str_ret)
        return (NULL);
    l_count_old = 0;
    while (str_old[l_count_old] != '\0')
    {
        str_ret[l_count_old] = str_old[l_count_old];
        l_count_old++;
    }
    l_count_read = 0;
    while (str_read[l_count_read] != '\0')
    {
        str_ret[l_count_old + l_count_read] = str_read[l_count_read];
        l_count_read++;
    }
    free(str_read);
    free(str_old);
    return (str_ret);
}

static char	*ft_read_feedback(int fd, long *l_read_res, char *str_com)
{
    char    *str_ret;
    //printf("\n----In function read---\n");
	str_ret = ft_calloc_char(BUFFER_SIZE + 1);
	if (!str_ret)
		return (NULL);
	*l_read_res = read(fd, str_ret, BUFFER_SIZE);
	if (*l_read_res <= 0)
	{
        free(str_com);
		free(str_ret);
		return (NULL);
	}
    str_ret = str_join_read(str_com, str_ret);
    if (!str_ret)
        return (NULL);
    return (str_ret);
}

long	ft_check_Newline(char *str_check)
{
	long	l_count;
	l_count = 0;
	while (str_check[l_count] != '\0')
	{
		if (str_check[l_count]  == '\n')
			return(l_count);
		l_count++;
	}
	return(-1);
}

int         ft_creat_string(char **str_mem, char **str_ret)
{
    //printf("\n--- in function creat String ----\n");
    if (!*str_mem)
    {
        *str_mem = ft_calloc_char(BUFFER_SIZE + 1);
        if(!*str_mem)
            return (1);
        *str_ret = ft_calloc_char(BUFFER_SIZE + 1);
        if(!*str_ret)
        {
            free(*str_mem);
            return (1);
        }
    }
    else
    {
        *str_ret = ft_calloc_char(ft_strlen(*str_mem) + 1);
        if(!*str_ret)
        {
            free(*str_mem);
            return (1);
        }
        ft_strncpy(*str_ret, *str_mem,ft_strlen(*str_mem));
    }
   //make printf("\nstr_mem |%p| -- str_ret |%p|\n", *str_mem, *str_ret);
    return (0);
}





char *get_next_line(int fd)
{
    char *str_ret;
    static char *str_mem ;
    long i_check_error;

    if(ft_creat_string(&str_mem, &str_ret))
        return (NULL);
    i_check_error = 0;
    while (i_check_error == 0)
    {
        str_ret = ft_read_feedback(fd, &i_check_error, str_ret);
        if (!str_ret)
        {
            free(str_mem);
            return (NULL);
        }
        //printf("\nstr_mem |%p| -- str_ret |%p|\n", str_mem, str_ret);
        if (i_check_error < BUFFER_SIZE)
            break;
        i_check_error = ft_check_Newline(str_ret);
        if (i_check_error != -1)
        {
            ft_strncpy(str_mem, str_ret + i_check_error + 1, ft_strlen(str_ret) - i_check_error );
            ft_strncpy(str_ret, str_ret, i_check_error);
            break ;
        }
        i_check_error = 0;
    }
    return(str_ret);
}


