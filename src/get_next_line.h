/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:48:05 by rkost             #+#    #+#             */
/*   Updated: 2023/08/24 10:49:08 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strdup(char *s1);
char	*ft_chrinstr(char *str, int chr);
char	*ft_substr(char *storage, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*ft_free(char **str);


#endif

// Fuction usesd inside get_next_line.c
// ------------------------------------
    // char	*ft_readbuf(int fd, char *storage) 
    // char	*ft_new_line(char *storage)
    // char	*ft_clean_storage(char *storage)