/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:06:06 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/16 17:06:07 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_width(t_game_root *root, char *file)
{
	root->game->map_width = 0;
	while (file[root->game->map_width] && file[root->game->map_width] != '\n')
		root->game->map_width++;
	if (root->game->map_width == 0 || file[root->game->map_width] == 0)
	{
		free(file);
		root_destroy(root, "map file is invalid", 0);
	}
}
