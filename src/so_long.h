/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:39:13 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/20 19:10:26 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include <mlx.h>
# include <mlx_int.h>
# include "../libft/libft.h"

typedef struct s_coordinates
{
	int				x;
	int				y;
}				t_coordinates;

typedef struct s_game
{
	int				**game_map;
	int				map_height;
	int				map_width;
	t_coordinates	player_position;
	int				player_up;
	int				player_down;
	int				player_left;
	int				player_right;
	int				player_move;
	int				player_collectible_count;
	t_coordinates	exit_position;
	t_coordinates	*collectibles;
	int				total_collectibles;
	int				total_exits;
	int				total_players;
}				t_game_state;

typedef struct s_root
{
	void			*mlx_instance;
	void			*mlx_window;
	t_img			*mlx_img;
	t_game_state	*game;
	t_img			*player;
	t_img			*exit_image;
	t_img			*collectible_image;
	t_img			*wall;
	t_img			*ground;
}				t_game_root;

void			render_frame(t_game_root *root);
int				handle_key_press(int keycode, t_game_root *root);
int				handle_key_release(int keycode, t_game_root *root);
int				handle_destroy_hook(int keycode, t_game_root *root);
void			free_game_resources(t_game_state *game);
void			calculate_map_height(t_game_root *root, char *file);
void			initialize_map(t_game_root *root, char *filename);
void			map_isvalid(t_game_root *root, char *file);
void			map_parsing(t_game_root *root, char *file);
void			map_width(t_game_root *root, char *file);
unsigned int	mlx_get_pixel(t_img *img, int x, int y);
void			mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);
void			move_up(t_game_root *root, int x, int y);
void			move_down(t_game_root *root, int x, int y);
void			move_left(t_game_root *root, int x, int y);
void			move_right(t_game_root *root, int x, int y);
void			root_destroy(t_game_root *root, char *errmsg, int errnum);
t_game_root		*root_init(char *filename);
void			update(t_game_root *root);
void			exit_with_error(char *error_msg, int error_num);
int				is_accessible(t_game_root *root);
t_coordinates	find_starting_position(char **map, t_coordinates size);

#endif
