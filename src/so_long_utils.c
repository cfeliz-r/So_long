/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:25:43 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/13 13:25:46 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	struct_initialize(t_data *mlx)
{
	mlx->mlx_ptr = 0;
	mlx->win_ptr = 0;
	mlx->x = 0;
	mlx->y = 0;
	mlx->p_x = 0;
	mlx->p_y = 0;
	mlx->lines = 0;
	mlx->columns = 0;
	mlx->map = 0;
	mlx->total_collectibles = 0;
	mlx->caught_collectibles = 0;
	mlx->last_side = 0;
	mlx->moves = 0;
	mlx->exits = 0;
	mlx->player = 0;
	mlx->fd = 0;
}

int	ft_keypress(int keysym, t_data *mlx)
{
	if (keysym == ESC)
		ft_xbutton(mlx);
	if (keysym == W)
		do_move(mlx, 'W');
	if (keysym == A)
		do_move(mlx, 'A');
	if (keysym == S)
		do_move(mlx, 'S');
	if (keysym == D)
		do_move(mlx, 'D');
	return (0);
}

size_t	ft_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_for_players(t_data *mlx, char c)
{
	if (c == 'P')
	{
		mlx->player++;
		return (1);
	}
	return (0);
}
