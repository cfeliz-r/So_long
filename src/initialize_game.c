/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:04:25 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/16 17:04:27 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game(t_game_root *root, char *filename)
{
	root->game = (t_game_state *)malloc(sizeof(t_game_state));
	if (root->game == 0)
		root_destroy(root, "initialize_game(): malloc()", errno);
	root->game->game_map = 0;
	root->game->collectibles_positions = 0;
	root->game->total_collectibles = 0;
	root->game->total_exits = 0;
	root->game->total_players = 0;
	root->game->player_move = 0;
	root->game->player_collectible_count = 0;
	root->game->player_up = 0;
	root->game->player_down = 0;
	root->game->player_left = 0;
	root->game->player_right = 0;
	initialize_map(root, filename);
}
