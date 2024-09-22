# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwadie-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 21:23:59 by jwadie-a          #+#    #+#              #
#    Updated: 2024/01/11 21:02:36 by jwadie-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS += -Wall -Wextra -Werror
MLXFLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lX11 -lXext
NAME = so_long
SRC_DIR = ./src/
LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
MLX_DIR = ./mlx/
MLX = $(MLX_DIR)libmlx.a

SRC=	main.c\
		parse_map.c\
		mlx_init.c\
		mlx_utils.c\
		check_invalid_1.c\
		check_invalid_2.c\
		handle_keypress.c\
		render.c\
		utils.c

SRC=	$(addprefix $(SRC_DIR),\
			check_invalid_1.c\
			check_invalid_2.c\
			death_sprites.c\
			enemies_list_utils.c\
			enemy_check.c\
			handle_keypress.c\
			load_enemies.c\
			main.c\
			mlx_init.c\
			mlx_load_images.c\
			mlx_utils.c\
			parse_map.c\
			render.c\
			render_enemies.c\
			render_list_utils.c\
			utils.c)

OBJ= $(SRC:%.c=%.o)

OBJ= $(SRC:%.c=%.o)

all: $(NAME)

$(LIBFT):
	cd $(LIBFT_DIR) && make

$(MLX):
	cd $(MLX_DIR) && make
	
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME) $(MLXFLAGS)

clean:
	cd $(LIBFT_DIR) && make fclean
	cd $(MLX_DIR) && make clean
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY:	all clean fclean re
