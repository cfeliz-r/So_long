/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_isvalid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:05:23 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/16 17:05:24 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	isborder(t_game_root *root, int i)
{
	if (i < root->game->map_width
		|| i > (root->game->map_width + 1) * (root->game->map_height - 1)
		|| i % (root->game->map_width + 1) == 0
		|| i % (root->game->map_width + 1) == root->game->map_width - 1)
		return (1);
	return (0);
}

static void	isvalid(t_game_root *root, char *file, int i)
{
	if (file[i] == 'P')
		root->game->total_players++;
	else if (file[i] == 'E')
		root->game->total_exits++;
	else if (file[i] == 'C')
		root->game->total_collectibles++;
	else if (file[i] == '1' || file[i] == '0')
		return ;
	else
	{
		free(file);
		root_destroy(root, "map content is invalid", 0);
	}
}

void	map_isvalid(t_game_root *root, char *file)
{
	int				i;

	i = -1;
	while (file[++i] != 0)
	{
		if (file[i] == '\n')
			continue ;
		if (isborder(root, i))
		{
			if (file[i] != '1')
			{
				free(file);
				root_destroy(root, "map isn't surrounded by walls", 0);
			}
		}
		else
			isvalid(root, file, i);
	}
	if (root->game->total_players != 1
		|| root->game->total_exits != 1
		|| root->game->total_collectibles < 1)
	{
		free(file);
		root_destroy(root, "map configuration is invalid", 0);
	}
}
