/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:59:33 by rkost             #+#    #+#             */
/*   Updated: 2023/07/02 13:05:19 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(int fd, long *l_read_ret)
{
	char	*str_read;

	str_read = ft_calloc_char(BUFFER_SIZE + 1);
	if (!str_read)
		return (NULL);
	*l_read_ret = read(fd, str_read, BUFFER_SIZE);
	if (*l_read_ret <= 0)
	{	
		free(str_read);
		return (NULL);
	}
	return (str_read);
}

long ft_check_newline(char *str)
{
	long l_count;
	//char *str_ret;
	//char  *str_mem;

	l_count = 0;
	while (str[l_count] != '\0')
	{
		// printf("%c\n",str[l_count]);
		if (str[l_count] == '\n')
		{
			// str_ret = ft_strdup(str, (ft_strlen(str) - l_count));
			// // str_mem = ft_strdup(str + l_count, ft_strlen(str));
		 	// printf("\n-----|%s|-----\n\n", str_ret);
			return (l_count);
		}
		l_count++;	
	}
	return (-1);
}


char	*get_next_line(int fd)
{
	
	//char	*str_line;
	char	*str_read;
	char	*str_ret;
	long	l_read_ret;
	//int		i_count_line;

	//Error Check
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//create read
	
	str_ret = ft_calloc_char(1);
	if (!str_ret)
		return (NULL);;
	str_read = ft_read(fd, &l_read_ret);
	while (str_read)
	{
		str_ret = ft_strlcat(str_ret, str_read);
		l_read_ret = ft_check_newline(str_ret);
		if (l_read_ret > -1)
		{
			str_ret = ft_strdup(str_ret, l_read_ret);
			break;
		}
		str_read = ft_read(fd, &l_read_ret);
	}
	if (!str_read)
	{
		free(str_ret);
		return (NULL);
	}
	
	
	// i_count_line = 0;
	// while (l_read_ret > 0)
	// {
	// 	ft_strlcat(str_line)
	// 	if (st_read == '\n')
	// 		break ;
	// 	i_read_ret = read(fd, &ch_read, 1);
	// }
	// str_line[i_count_line] = '\0';
	return (str_ret);
}
