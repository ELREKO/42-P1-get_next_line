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

static char	*ft_read_the_hole_file(int fd)
{
	char	*str_read;
	char 	*str_mem;
	long	l_read_ret;
	
	str_read = ft_calloc_char(BUFFER_SIZE + 1);
	str_mem = ft_calloc_char(1);
	if(!str_read || !str_mem)
		return (NULL);
	l_read_ret = read(fd, str_read, BUFFER_SIZE);
	if (l_read_ret <= 0)
	{	
		free(str_read);
		free(str_mem);
		return (NULL);
	}
	while(str_read)
	{
		str_mem = ft_strlcat(str_mem, str_read);
		if(!str_mem)
			return (NULL);
		l_read_ret = 0;
		while(str_read[l_read_ret] != '\0')
			str_read[l_read_ret] = '\0';
		l_read_ret = read(fd, str_read, BUFFER_SIZE);
		if (l_read_ret == 0)
			break ;
if(l_read_ret < -1)
		{free(str_read);
return NULl}
	}
free(str_read);
	return(str_mem);
}

int ft_check_next_newline(char *str)
{
	unsigned int ui_test;
	
	ui_test=0;
	while (str[ui_test])
	{
		if (str[ui_test] == '\n')
			return (1);
		ui_test++;
	}
	return(0);
}

char	*get_next_line(int fd)
{
	static char *str_mem;
	long 	l_count;
	char	*str_ret;
	char	*str_buffer;

	//Importeant Check
	if (fd < 0 || BUFFER_SIZE <= 0)// || read(fd, 0, 0) <= 0)
		return (NULL);
	if (str_mem == NULL)
	{	
		str_mem = ft_read_the_hole_file(fd);
		if (str_mem == NULL)
			return (NULL);
	}
	l_count = 0;
	if (ft_check_next_newline(str_mem))
	{
		while(str_mem[l_count++])
		{
			if (str_mem[l_count] == '\n')
			{	
				str_ret = ft_strdup(str_mem, l_count);
				str_buffer = ft_strdup(str_mem + l_count + 1, ft_strlen(str_mem) - l_count);
				if (!str_ret || !str_buffer)
					return (NULL);
				free(str_mem);
				str_mem = ft_strdup(str_buffer, ft_strlen(str_buffer));
				if (!str_mem)
					return (NULL);
				free(str_buffer);
				return (str_ret);	
			}
		}
	}
	str_ret = ft_strdup(str_mem, ft_strlen(str_mem));
	str_mem = NULL;
	return(str_ret);
}
