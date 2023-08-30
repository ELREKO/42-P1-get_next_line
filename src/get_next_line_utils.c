/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:29:14 by rkost             #+#    #+#             */
/*   Updated: 2023/08/24 10:29:23 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*str_ret;
	size_t	i_count_str1;
	size_t	i_count_str2;

	if (!str1)
	{
		str1 = malloc(sizeof(char) + 1);
		if (!str1)
			return (0);
		str1[0] = 0;
	}
	str_ret = malloc(sizeof(char) * ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!str_ret)
		return (ft_free(&str1));
	i_count_str1 = -1;
	while (str1[++i_count_str1])
		str_ret[i_count_str1] = str1[i_count_str1];
	i_count_str2 = -1;
	while (str2[++i_count_str2])
		str_ret[i_count_str1 + i_count_str2] = str2[i_count_str2];
	str_ret[i_count_str1 + i_count_str2] = '\0';
	free(str1);
	return (str_ret);
}

size_t	ft_strlen(char *str)
{
	size_t	i_count;

	i_count = 0;
	if (!str)
		return (0);
	while (str[i_count] != '\0')
		i_count++;
	return (i_count);
}

char	*ft_chrinstr(char *str, int chr)
{
	int	i_count;

	i_count = 0;
	while (str[i_count] != '\0')
	{
		if (str[i_count] == (char)chr)
			return (&((char *)str)[i_count]);
		i_count++;
	}
	if ((char)chr == '\0')
		return (&((char *)str)[i_count]);
	return (0);
}

char	*ft_substr(char *storage, unsigned int start, size_t len)
{
	size_t	i_count;
	char	*str_ret;

	i_count = 0;
	if (!storage)
		return (0);
	if (start > ft_strlen(storage))
	{
		str_ret = malloc(sizeof(char) * (1));
		if (!str_ret)
			return (NULL);
		str_ret[0] = '\0';
		return (str_ret);
	}
	if (ft_strlen(storage) - start < len)
		len = ft_strlen(storage) - start;
	str_ret = malloc(sizeof(char) * (len + 1));
	if (!str_ret)
		return (NULL);
	while (start < ft_strlen(storage) && i_count < len && storage[start])
		str_ret[i_count++] = storage[start++];
	str_ret[i_count] = '\0';
	return (str_ret);
}
