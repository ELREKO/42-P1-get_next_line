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

// char *ft_read(int fd, long *l_read_ret)
// {
// 	char	*str_read;

// 	str_read = ft_calloc_char(BUFFER_SIZE + 1);
// 	if (!str_read)
// 		return (NULL);
// 	*l_read_ret = read(fd, str_read, BUFFER_SIZE);
// 	if (*l_read_ret <= 0)
// 	{	
// 		free(str_read);
// 		return (NULL);
// 	}
// 	return (str_read);
// }

// // char *ft_check_newline(char *str, char **str_store)
// {
// 	long l_count;
// 	char *str_ret;
// 	char  *str_mem;

// 	l_count = 0;
// 	str_mem = ft_strdup(str, ft_strlen(str));
// 	if (!str_mem)
// 		return (NULL);
// 	//printf("\n\nstr Mem: |%s| str|%s| \n\n",str_mem, str);
// 	while (str_mem[l_count] != '\0')
// 	{
// 	 	if (str_mem[l_count] == '\n')
// 	 	{
// 	// 		printf("YES");
// 	 		str_ret = ft_strdup(str_mem, l_count);
// 	 		*str_store = ft_strdup(str_mem + l_count + 1, ft_strlen(str_mem));
// 	// 		//printf("\n I am in: \n str: Mem|%s|\nstr_ret|%s|\nstr_store |%s|", str_mem, str_ret, *str_store);
// 	 		if (!str_ret)
// 	 			return (NULL);
// 	 		free(str_mem);
// 	 		free(str);
// 			//printf("%s \n|%s|\n", str_ret, *str_store);
// 	 		return (str_ret);
// 		}
// 	 	l_count++;	
// 	}
// 	*str_store = NULL;
// 	free(str);
// 	return (str_mem);
// }


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
	while(str_read)
	{
		str_mem = ft_strlcat(str_mem, str_read);
		l_read_ret = 0;
		while(str_read[l_read_ret] != '\0')
			str_read[l_read_ret] = '\0';
		l_read_ret = read(fd, str_read, BUFFER_SIZE);
		if (l_read_ret <= 0)
		{
			free(str_read);
			break ;
		}
	}
	if (l_read_ret == -1)
		return (NULL);
	return(str_mem);
}

char	*get_next_line(int fd)
{
	static char *str_mem;
	//char	*str_ret;
	//Importeant Check
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str_mem)
	{	
		str_mem = ft_read_the_hole_file(fd);
		if (str_mem == NULL)
			return (NULL);
		return (str_mem);
	}
	return (NULL);
	
}
