NAME			= libft.a

# LIBFT
LIBFT_SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c \
					ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c \
					ft_striteri.c ft_isalnum.c \
					ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
					ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
					ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

# GNL
GNL_SRCS    		=	get_next_line_bonus.c get_next_line_utils_bonus.c

# PRINTF
PRINTF_SRCS 		=	ft_printf_bonus.c ft_putchar_bonus.c ft_print_char_bonus.c \
					ft_print_str_bonus.c ft_putnbr_bonus.c ft_putnbr_utils_bonus.c \
					ft_putunbr_bonus.c ft_print_hex_bonus.c ft_putptr_bonus.c ft_parse_bonus.c

ALL_SRCS    = $(LIBFT_SRCS) $(GNL_SRCS) $(PRINTF_SRCS)
OBJS			= $(ALL_SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
AR          	= ar rcs

all:			$(NAME)

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re
