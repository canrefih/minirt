/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recan <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:39:53 by recan             #+#    #+#             */
/*   Updated: 2025/10/07 14:39:54 by recan            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

/*libft*/
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nelem, size_t elsize);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*libft bonus*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*gnl*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
int		ft_checkstr(char *s);
char	*ft_strndup(const char *s1, int size);

/*printf*/
typedef struct s_flag
{
	int		minus;
	int		zero;
	int		hash;
	int		plus;
	int		space;
	int		width;
	int		dot;
	int		precision;
	char	spec;
}	t_flag;

int		ft_putchar(int c);
int		ft_print_char(char c, t_flag *f);
int		ft_printf(const char *format, ...);
int		ft_print_format(va_list arg, t_flag *f);
int		ft_parse_all(va_list arg, const char *format, t_flag *f, int *i);
void	ft_init_flag(t_flag *f);
void	ft_parse_flags(const char *format, int *i, t_flag *f);
void	ft_parse_width(const char *format, int *i, t_flag *f);
void	ft_parse_precision(const char *format, int *i, t_flag *f);
int		ft_print_str(char *str, t_flag *f);
int		ft_putnbr(int n, t_flag *f);
int		ft_print_sign(long *nb, t_flag *f);
char	ft_get_pad_char(t_flag *f);
int		ft_get_nbr_len(long nb, t_flag *f);
int		ft_get_sign_len(long nb, t_flag *f);
int		ft_print_padding(int len, char c);
int		ft_putunbr(unsigned int n, t_flag *f);
int		ft_putptr(unsigned long ptr, t_flag *f);
int		ft_print_hex(unsigned int n, int upper, t_flag *f);
int		ft_hex_len(unsigned int n);
int		ft_puthex(unsigned int n, int upper);
int		ft_calc_hex_len(unsigned int n, t_flag *f);
int		ft_print_hex_padding(unsigned int n, t_flag *f, int *len);

#endif
