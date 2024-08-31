NAME = so_long
CC = cc
SRC = src/images.c \
			src/init.c \
			src/main.c \
			src/map.c \
			src/player_movement.c
OBJS = $(SRC:.c=.o) 
CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address,leak
MLX_FLAGS = -lXext -lX11 -lm -lbsd
MLX_PATH = mlx_linux/libmlx.a
LIBFT_PATH = libft/libft.a
INCLUDES = -I/usr/include

all: $(NAME) 

$(MLX_PATH) :
	@make -C mlx_linux

$(LIBFT_PATH) :
	@make -C libft
$(NAME): $(OBJS) $(LIBFT_PATH) $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_PATH) $(MLX_FLAGS) $(LIBFT_PATH) -o $(NAME)
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C libft clean
	@$(MAKE) -C mlx_linux clean
	rm -f $(OBJS)
fclean: clean
	@$(MAKE) -C libft fclean
	@$(MAKE) -C mlx_linux clean
	rm -f $(NAME)
run:
	$./(NAME) maps/map.ber

re: fclean all

.PHONY :all clean fclean run re 




