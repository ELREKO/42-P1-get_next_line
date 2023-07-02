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

char	*ft_strdup(char *str)
{
	char	*str_ret;
	size_t	ui_count;

	str_ret = (char *)malloc(sizeof(char *) * ft_strlen(str) + 1);
	if (!str_ret)
		return (NULL);
	ui_count = 0;
	while (str[ui_count] != '\0')
	{
		str_ret[ui_count] = str[ui_count];
		ui_count++;
	}
	str_ret[ui_count] = '\0';
	return (str_ret);
}
