NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address,undefined
MLX_DIR		=	mlx
LFT			=	libft/libft.a
INC			=	-I ./inc -I ./libft -I ./mlx
LIB			=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd

SRC			=	src/die.c \
				src/draw.c \
				src/event.c \
				src/game_destroy.c \
				src/game_init.c \
				src/map_height.c \
				src/map_init.c \
				src/map_isvalid.c \
				src/map_parsing.c \
				src/map_read.c \
				src/map_width.c \
				src/mlx_utils.c \
				src/move_player.c \
				src/root_destroy.c \
				src/root_init.c \
				src/so_long.c \
				src/update.c

# Convertir la lista de archivos fuente en archivos objeto
OBJ			=	$(SRC:src/%.c=obj/%.o)

all:		$(MLX_DIR)/libmlx.a $(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(MLX_DIR)/libmlx.a:
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C $(MLX_DIR)
			@echo " [ OK ] | Minilibx ready!"

$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C libft
			@make -s clean -C $(MLX_DIR)
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re

