/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:05:55 by rkost             #+#    #+#             */
/*   Updated: 2023/07/02 13:09:31 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef BUFFER_SIZE
	#define BUFFER_SIZE 6
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>


size_t	ft_strlen(char *str)
{
	size_t	ui_count;

	ui_count = 0;
	while (str[ui_count] != '\0')
		ui_count++;
	return (ui_count);
}

char *ft_calloc_char(size_t size)
{
	char	*str_ret;
	size_t	ui_count;

	str_ret = (char *)malloc(sizeof(char *) * size);
	if (!str_ret)
		return (NULL);
	ui_count = 0;
	while (ui_count <= size)
		str_ret[ui_count++] = '\0';
	return (str_ret);
}

char	*ft_strdup(char *str, unsigned int size)
{
	char	*str_ret;
	size_t	ui_count;

	str_ret = ft_calloc_char(size + 1);
	if (!str_ret)
		return (NULL);
	ui_count = 0;
	//printf(" -- %d -- \n", size);
	while (str[ui_count] != '\0' && ui_count <= size)
	{
		str_ret[ui_count] = str[ui_count];
		ui_count++;
	}
	str_ret[ui_count] = '\0';
	return (str_ret);
}

char *ft_strlcat(char *s1, char *s2)
{
	long ui_copy_s1;
	long ui_copy_s2;
	char *str_ret;
	str_ret = ft_calloc_char(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str_ret || !s1)
		return (NULL);
	ui_copy_s1 = -1;
	while (s1[++ui_copy_s1] != '\0')
		str_ret[ui_copy_s1] = s1[ui_copy_s1];
	ui_copy_s2 = -1;
	while (s2[++ui_copy_s2] != '\0')
		str_ret[ui_copy_s2 + ui_copy_s1] = s2[ui_copy_s2];
	str_ret[ui_copy_s2 + ui_copy_s1] = '\0';
	free(s1);
	//free(s2);
	return (str_ret);
}

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
		l_read_ret = -1;
		while(str_read[++l_read_ret] != '\0')
			str_read[l_read_ret] = '\0';
		l_read_ret = read(fd, str_read, BUFFER_SIZE);
		if (l_read_ret <= 0)
			break ;
	}
	free(str_read);
	return(str_mem);
}


char	*get_next_line(int fd)
{
	static char *str_mem;
	long 	l_count;
	char	*str_ret;
	char	*str_buffer;

	//Importeant Check
	// if (read(fd, 0, 0) <= 0)
	// 	return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str_mem)
	{	
		str_mem = ft_read_the_hole_file(fd);
		if (!str_mem)
			return (NULL);
	}
	l_count = 0;
	while(str_mem[l_count++])
	{
		if (str_mem[l_count] == '\n')
		{	
			str_ret = ft_strdup(str_mem, l_count);
			str_buffer = ft_strdup(str_mem + l_count + 1, ft_strlen(str_mem) - l_count);
			if (!str_ret || !str_buffer)
				return (NULL);
			str_mem = NULL;
			str_mem = ft_strdup(str_buffer, ft_strlen(str_buffer));
			if (!str_mem)
				return (NULL);
			str_buffer = NULL;
			return (str_ret);	
		}
	}
	str_ret = ft_strdup(str_mem, ft_strlen(str_mem));
	str_mem = NULL;
	return(str_ret);
}


int main(void) 
{
    int fd;
    char *str_read;

    fd = open("Test.txt", O_RDONLY);
    if (fd < 0) {
        perror("r1");
        exit(1);
    }
    int i = 1;

    str_read = get_next_line(fd);
    while (str_read)
    {
        printf("Line: %d -->",i);
        printf("%s", str_read);
        free(str_read);
        str_read = get_next_line(fd);
        printf("\n-----------------Pointer-----------: %p\n", (void*)get_next_line);
        i++;
    }
    free(str_read);
    
    int result = close(fd);
    if (result < 0) {
        perror("Error closing file");
        exit(1);
    }
    return (0);
}

