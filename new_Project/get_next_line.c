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

char *ft_check_newline(char *str, char **str_store)
{
	long l_count;
	char *str_ret;
	char  *str_mem;

	l_count = 0;
	str_mem = ft_strdup(str, ft_strlen(str));
	if (!str_mem)
		return (NULL);
	//printf("\n\nstr Mem: |%s| str|%s| \n\n",str_mem, str);
	while (str_mem[l_count] != '\0')
	{
	 	if (str_mem[l_count] == '\n')
	 	{
	// 		printf("YES");
	 		str_ret = ft_strdup(str_mem, l_count);
	 		*str_store = ft_strdup(str_mem + l_count + 1, ft_strlen(str_mem));
	// 		//printf("\n I am in: \n str: Mem|%s|\nstr_ret|%s|\nstr_store |%s|", str_mem, str_ret, *str_store);
	 		if (!str_ret)
	 			return (NULL);
	 		free(str_mem);
	 		free(str);
			printf("%s \n|%s|\n", str_ret, *str_store);
	 		return (str_ret);
		}
	 	l_count++;	
	}
	*str_store = NULL;
	free(str);
	return (str_mem);
}

char	*get_next_line(int fd)
{
	char	*str_read;
	char	*str_ret;
	//static char	*str_mem;
	long	l_read_ret;
	//int		i_count_line;

	//Error Check
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	// if (str_mem)
	// 	str_ret = ft_check_newline(str_mem, &str_read);
	// if(str_read == NULL)
	// {	
		str_read = ft_read(fd, &l_read_ret);
		str_ret = ft_calloc_char(1);
		if (!str_ret)
			return (NULL);
	// }
	// else
	// {
	// 	free(str_read);
	// 	return(str_ret);
	// }
	while (str_read)
	{
		str_ret = ft_strlcat(str_ret, str_read);
		if (!str_ret)
			return (NULL);
		//--> Checke till here is okay Newline is important		
		str_ret = ft_check_newline(str_ret, &str_read);
		if (str_read != NULL)
		{
			//str_mem = ft_strdup(str_read, ft_strlen(str_read));
			free(str_read);
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
