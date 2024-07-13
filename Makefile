# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/13 13:57:09 by cfeliz-r          #+#    #+#              #
#    Updated: 2024/07/13 14:04:08 by cfeliz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address,undefined
MFLAGS = -lX11 -lXext
RM = rm -rf

LIBFT = ./libft/libft.a
MLX = ./minilibx-linux/libmlx_Linux.a

SRCS =		src/so_long.c \
		src/so_long_free2.c \
		src/so_long_map_verify2.c \
		src/so_long_draw_map2.c \
		src/so_long_free.c \
		src/so_long_map_verify.c \
		src/so_long_draw_map.c \
		src/so_long_map_handler.c \
		src/so_long_movements.c \
		src/so_long_enemy.c \
		src/so_long_map_handler_utils.c \
		src/so_long_utils.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(MLX):
	@$(MAKE) -C ./minilibx-linux


$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MFLAGS) -o $(NAME)
	cp $(LIBFT) .

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) libft.a
re: fclean all
