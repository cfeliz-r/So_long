/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_map2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:19:45 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/13 13:19:50 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	insert_others(t_data *mlx, int i, int j)
{
	if (mlx->map[i][j] == '0')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->floor_img, mlx->x, mlx->y);
	if (mlx->map[i][j] == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->char_r_img, mlx->x, mlx->y);
	if (mlx->map[i][j] == 'C')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->coll_img, mlx->x, mlx->y);
	if (mlx->map[i][j] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->exit_img, mlx->x, mlx->y);
	if (mlx->map[i][j] == 'I')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->enemy_w_img, mlx->x, mlx->y);
}

int	put_walls(t_data *mlx, int i, int j)
{
	if (i == 0 && j == 0)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->corner_tl, mlx->x, mlx->y);
		return (1);
	}
	else if (i == 0 && j == mlx->columns - 1)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->corner_tr, mlx->x, mlx->y);
		return (1);
	}
	else if (i == mlx->lines - 1 && j == 0)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->corner_bl, mlx->x, mlx->y);
		return (1);
	}
	else if (i == mlx->lines - 1 && j == mlx->columns - 1)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->corner_br, mlx->x, mlx->y);
		return (1);
	}
	return (0);
}

int	ft_animation(t_data *mlx)
{
	static int	i;
	int			num;

	num = 20000;
	i++;
	if (i == num * 2)
		collectible_coordinates(mlx, 1);
	if (i == num * 3)
		ft_enemies(mlx);
	if (i == num * 4)
	{
		collectible_coordinates(mlx, 2);
		i = 0;
	}
	return (1);
}

void	collectible_coordinates(t_data *mlx, int flag)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->lines)
	{
		x = 0;
		while (x < mlx->columns)
		{
			if (mlx->map[y][x] == 'C')
			{
				if (flag == 1)
					mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
						mlx->coll_2_img, x * 16, y * 16);
				if (flag == 2)
					mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
						mlx->coll_img, x * 16, y * 16);
			}
			x++;
		}
		y++;
	}
}

void	check_position(t_data *mlx)
{
	if (mlx->map[mlx->p_y][mlx->p_x] == 'I')
	{
		ft_printf("\033[0;31m💀You Died. LOSER!!💀\033[0;37m\n");
		ft_xbutton(mlx);
	}
	if (mlx->map[mlx->p_y][mlx->p_x] == 'C')
	{
		mlx->caught_collectibles++;
		mlx->map[mlx->p_y][mlx->p_x] = '0';
	}
	if (mlx->map[mlx->p_y][mlx->p_x] == 'E'
		&& mlx->caught_collectibles == mlx->total_collectibles)
	{
		ft_printf("\033[0;32mCongratulations, you reached the end!🚩\033[0;37m\n");
		ft_xbutton(mlx);
	}
}
