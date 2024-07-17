/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:06:25 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/16 17:06:27 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game_root *root, int x, int y)
{
	if (root->game->game_map[y - 1][x] == 0)
		root->game->player_position.y -= 1;
}

void	move_down(t_game_root *root, int x, int y)
{
	if (root->game->game_map[y + 1][x] == 0)
		root->game->player_position.y += 1;
}

void	move_left(t_game_root *root, int x, int y)
{
	if (root->game->game_map[y][x - 1] == 0)
		root->game->player_position.x -= 1;
}

void	move_right(t_game_root *root, int x, int y)
{
	if (root->game->game_map[y][x + 1] == 0)
		root->game->player_position.x += 1;
}
