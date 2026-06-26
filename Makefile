NAME        = miniRT

LIBFT_DIR   = lib/libft
LIBFT       = $(LIBFT_DIR)/libft.a

MLX_DIR     = lib/minilibx/minilibx-linux
MLX         = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# ===================== SOURCES =====================

SRC = src/main.c \
      src/init.c \
      src/render.c \
      src/render_utils.c \
      src/ray.c \
      src/sphere.c \
      src/cylinder.c \
      src/cylinder_utils.c\
      src/plane.c \
      src/hit_object.c \
      src/vec3.c \
      src/vec3_cn.c \
      src/parser.c \
      src/parse_utils.c \
      src/parse_features.c \
      src/utils.c

OBJ = $(SRC:.c=.o)

# ===================== FLAGS =====================

INC     = -Iinclude -I$(MLX_DIR) -I$(LIBFT_DIR)
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

# ===================== RULES =====================

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

# ===================== LIBFT =====================

$(LIBFT):
	@make -C $(LIBFT_DIR)

# ===================== COMPILATION =====================

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# ===================== CLEAN =====================

clean:
	$(RM) $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus