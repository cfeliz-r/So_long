/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:39:13 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/16 19:53:40 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include <mlx.h>
# include <mlx_int.h>
# include "libft.h"

typedef struct s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef struct s_game
{
	int				**map;
	int				height;
	int				width;
	t_coord			player;
	int				player_up;
	int				player_down;
	int				player_left;
	int				player_right;
	int				player_move;
	int				player_coll;
	t_coord			exit;
	t_coord			*coll;
	int				count_coll;
	int				count_exit;
	int				count_player;
}				t_game;

typedef struct s_root
{
	void			*mlx;
	void			*mlx_win;
	t_img			*mlx_img;
	t_game			*game;
	t_img			*player;
	t_img			*exit;
	t_img			*coll;
	t_img			*wall;
	t_img			*ground;
}				t_root;

void			exit_with_error(char *errmsg, int errnum);
void			render_frame(t_root *root);
int				handle_key_press(int keycode, t_root *root);
int				handle_key_release(int keycode, t_root *root);
int				handle_destroy_hook(int keycode, t_root *root);
void			game_destroy(t_game *game);
void			game_init(t_root *root, char *filename);
void			map_height(t_root *root, char *file);
void			map_init(t_root *root, char *filename);
void			map_isvalid(t_root *root, char *file);
void			map_parsing(t_root *root, char *file);
void			map_read(t_root *root, char *file);
void			map_width(t_root *root, char *file);
unsigned int	mlx_get_pixel(t_img *img, int x, int y);
void			mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);
void			move_up(t_root *root, int x, int y);
void			move_down(t_root *root, int x, int y);
void			move_left(t_root *root, int x, int y);
void			move_right(t_root *root, int x, int y);
void			root_destroy(t_root *root, char *errmsg, int errnum);
t_root			*root_init(char *filename);
void			update(t_root *root);

#endif
