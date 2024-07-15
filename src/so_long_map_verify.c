/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_verify.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:25:15 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/14 00:23:28 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_verifications(t_data *mlx)
{
	if (mlx->lines < 3 || mlx->columns < 3)
	{
		ft_putstr_fd("\033[0;31mError\nMap is too short!❌\033[0;37m\n", 2);
		return (0);
	}
	if (!line_length(mlx))
		return (0);
	if (mlx->exits != 1 || mlx->player != 1 || mlx->total_collectibles < 1)
	{
		ft_putstr_fd("Error\nInvalid number of items!\n", 2);
		return (0);
	}
	if (!closed_map(mlx))
	{
		ft_putstr_fd("\033[0;31mError\nMap is not closed!❌\033[0;37m\n", 2);
		return (0);
	}
	if (!map_verifications2(mlx))
		return (0);
	return (1);
}

int	mapname(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.')
		i++;
	if (str[i] != '.' || str[i + 1] != 'b' || str[i + 2] != 'e'
		|| str[i + 3] != 'r' || str[i + 4] != '\0')
	{
		ft_putstr_fd("\033[0;31mError\nInvalid map name!❌\033[0;37m\n", 2);
		return (0);
	}
	return (1);
}

int	line_length(t_data *mlx)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < mlx->lines)
	{
		while (mlx->map[y][x])
			x++;
		if (x == mlx->columns)
		{
			y++;
			x = 0;
		}
		else
		{
			ft_putstr_fd("\033[0;31mError\nMap's not rectangular!❌\033[0;37m\n", 2);
			return (0);
		}
	}
	return (1);
}

void	three_columns(t_data *mlx, char *move_number)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->black_img, 20, mlx->lines * 16 + 5);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20,
		mlx->lines * 16 + 15, 0xFFFFFF, move_number);
}
