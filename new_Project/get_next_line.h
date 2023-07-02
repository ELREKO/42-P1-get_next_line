/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 13:11:55 by rkost             #+#    #+#             */
/*   Updated: 2023/07/02 13:21:42 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
	#define BUFFER_SIZE 6
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

//get_next_line.c
char	*get_next_line(int fd);
//get_next_line_utils.c
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);

#endif
