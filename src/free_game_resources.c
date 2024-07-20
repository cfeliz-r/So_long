/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:04:05 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/16 17:04:06 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game_resources(t_game_state *game)
{
	int				i;

	if (game != 0)
	{
		if (game->collectibles != 0)
			free(game->collectibles);
		if (game->game_map != 0)
		{
			i = 0;
			while (i < game->map_height)
				free(game->game_map[i++]);
			free(game->game_map);
		}
		free(game);
	}
}
