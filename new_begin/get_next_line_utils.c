/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:07:59 by rkost             #+#    #+#             */
/*   Updated: 2023/06/29 13:14:30 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	ui_count;

	ui_count = 0;
	if (!str)
		return (0);
	while (*str++ != '\0')
		ui_count++;
	return (ui_count);
}

char	*ft_strncpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	ui_count;

	ui_count = 0;
	while (src[ui_count] != '\0' && ui_count <= size)
	{
		dest[ui_count] = src[ui_count];
		ui_count++;
	}
	dest[ui_count] = '\0';
	return (dest);
}

void	ft_bzero(void *str, size_t ui_len)
{
	unsigned char	*mem;
	size_t			ui_count;

	mem = (unsigned char *)str;
	ui_count = 0;
	while (ui_count < ui_len)
	{
		mem[ui_count] = '\0';
		ui_count++;
	}
	str = mem;
}

char	*ft_calloc_char(size_t size)
{
	char	*str_ret;

	str_ret = (char *)malloc(sizeof(char *) * size);
	if (!str_ret)
		return (NULL);
	ft_bzero(str_ret, size);
	return (str_ret);
}
