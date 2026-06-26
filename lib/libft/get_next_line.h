/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.h                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/22 09:51:34 by recan          #+#    #+#                */
/*   Updated: 2026/01/22 09:51:37 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
int		ft_checkstr(char *s);
char	*ft_strndup(const char *s1, int size);

#endif
