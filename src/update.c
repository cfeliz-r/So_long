/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:07:27 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/16 17:07:28 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	had_move(t_root *root, int x, int y)
{
	if (root->game->player.x != x || root->game->player.y != y)
	{
		root->game->player_move++;
		ft_putnbr_fd(root->game->player_move, 1);
		ft_putendl_fd("", 1);
	}
}

static void	iscollectable(t_root *root)
{
	int				k;

	k = 0;
	while (k < root->game->count_coll)
	{
		if (root->game->collectibles_positions[k].x == root->game->player.x
			&& root->game->collectibles_positions[k].y == root->game->player.y)
		{
			root->game->collectibles_positions[k].x = -1;
			root->game->collectibles_positions[k].y = -1;
			root->game->player_coll++;
		}
		k++;
	}
}

void	update(t_root *root)
{
	int				x;
	int				y;

	x = root->game->player.x;
	y = root->game->player.y;
	if (root->game->player_up != 0)
		move_up(root, x, y);
	else if (root->game->player_down != 0)
		move_down(root, x, y);
	else if (root->game->player_left != 0)
		move_left(root, x, y);
	else if (root->game->player_right != 0)
		move_right(root, x, y);
	had_move(root, x, y);
	iscollectable(root);
	render_frame(root);
	if (root->game->exit_position.x == root->game->player.x
		&& root->game->exit_position.y == root->game->player.y)
		if (root->game->count_coll == root->game->player_coll)
			root_destroy(root, 0, 0);
}
