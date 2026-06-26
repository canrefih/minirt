/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line_bonus.h                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: recan <marvin@42.fr>                          +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/01/22 10:07:02 by recan          #+#    #+#                */
/*   Updated: 2026/01/22 10:07:04 by recan          ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
int		ft_checkstr(char *s);
char	*ft_strndup(const char *s1, int size);

#endif
