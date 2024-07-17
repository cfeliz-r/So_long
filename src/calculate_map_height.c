/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:04:51 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/16 17:04:53 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_map_height(t_game_root *root, char *file)
{
	int				i;
	int				j;

	root->game->map_height = 1;
	i = root->game->map_width + 1;
	while (file[i] != 0)
	{
		j = 0;
		while (file[i + j] != 0 && file[i + j] != '\n')
			j++;
		if (root->game->map_width != j)
		{
			free(file);
			root_destroy(root, "map format is invalid", 0);
		}
		i += root->game->map_width + 1;
		root->game->map_height++;
	}
}
