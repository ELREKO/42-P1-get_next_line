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

char	*get_next_line(int fd)
{
	char	ch_read;
	char	str_line[7000000];
	int		i_read_ret;
	int		i_count_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i_read_ret = read(fd, &ch_read, 1);
	i_count_line = 0;
	while (i_read_ret > 0)
	{
		str_line[i_count_line++] = ch_read;
		if (ch_read == '\n')
			break ;
		i_read_ret = read(fd, &ch_read, 1);
	}
	str_line[i_count_line] = '\0';
	if (i_read_ret <= 0 && i_count_line == 0)
		return (NULL);
	return (ft_strdup(str_line));
}
