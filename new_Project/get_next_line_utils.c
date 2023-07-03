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

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	ui_count;

	ui_count = 0;
	while (str[ui_count] != '\0')
		ui_count++;
	return (ui_count);
}

// char	*ft_strdup(char *str, unsigned int size)
// {
// 	char	*str_ret;
// 	size_t	ui_count;

// 	str_ret = ft_calloc_char(size + 1);
// 	if (!str_ret)
// 		return (NULL);
// 	ui_count = 0;
// 	//printf(" -- %d -- \n", size);
// 	while (str[ui_count] != '\0' && ui_count <= size)
// 	{
// 		str_ret[ui_count] = str[ui_count];
// 		ui_count++;
// 	}
// 	str_ret[ui_count] = '\0';
// 	return (str_ret);
// }

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