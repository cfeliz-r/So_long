/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:03:45 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/16 17:03:47 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_image_square(t_game_root *root, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(root->mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

static void	draw_environment_objects(t_game_root *root, int i, int j)
{
	int				k;

	if (root->game->exit_position.x == i && root->game->exit_position.y == j)
		draw_image_square(root, root->exit_image, i * 40, j * 40);
	k = -1;
	while (++k < root->game->total_collectibles)
		if (root->game->collectibles_positions[k].x == i && root->game->collectibles_positions[k].y == j)
			draw_image_square(root, root->collectible_image, i * 40, j * 40);
	if (root->game->player_position.x == i && root->game->player_position.y == j)
		draw_image_square(root, root->player, i * 40, j * 40);
}

static void	render_game_map(t_game_root *root)
{
	int				i;
	int				j;

	j = 0;
	while (j < root->game->map_height)
	{
		i = 0;
		while (i < root->game->map_width)
		{
			if (root->game->game_map[j][i] == 1)
				draw_image_square(root, root->wall, i * 40, j * 40);
			else
				draw_image_square(root, root->ground, i * 40, j * 40);
			draw_environment_objects(root, i, j);
			i++;
		}
		j++;
	}
}

void	render_frame(t_game_root *root)
{
	render_game_map(root);
	mlx_put_image_to_window(root->mlx_instance, root->mlx_window, root->mlx_img, 0, 0);
}
