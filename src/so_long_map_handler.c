/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:24:16 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/13 13:24:23 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	do_move(t_data *mlx, char flag)
{
	if (flag == 'W' && check_wall(mlx, 'W'))
		move_w(mlx);
	else if (flag == 'S' && check_wall(mlx, 'S'))
		move_s(mlx);
	else if (flag == 'A' && check_wall(mlx, 'A'))
		move_a(mlx);
	else if (flag == 'D' && check_wall(mlx, 'D'))
		move_d(mlx);
	return (0);
}

void	load_map(t_data *mlx, char *file)
{
	int		i;
	int		j;

	map_prepare(mlx, file);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->columns * 16,
			mlx->lines * 16 + 20, "so_long");
	i = 0;
	while (i < mlx->lines)
	{
		j = 0;
		while (mlx->map[i][j] != '\0')
		{
			insert_wall(mlx, i, j);
			insert_others(mlx, i, j);
			mlx->x += 16;
			j++;
		}
		mlx->x = 0;
		mlx->y += 16;
		i++;
	}
}
