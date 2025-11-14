NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = ./mlx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_INC = -I$(MLX_DIR)

RM = rm -rf

SRC = cub3d.c check_maps.c check_map_name.c is_validmap.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c rgb.c \
	mlx_func.c draw_maps.c

OBJS = $(SRC:.c=.o)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean :
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean : clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : clean fclean re all