/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_map_height.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:04:51 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/20 15:30:17 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_map_height(t_game_root *root, char *file)
{
	int		i;
	int		line_length;

	i = 0;
	root->game->map_height = 1;
	while (file[i] != '\0')
	{
		line_length = 0;
		while (file[i] != '\0' && file[i] != '\n')
		{
			line_length++;
			i++;
		}
		if (line_length != root->game->map_width)
		{
			free(file);
			root_destroy(root, "map format is invalid", 0);
			return ;
		}
		if (file[i] == '\n')
			i++;
		if (file[i] != '\0')
			root->game->map_height++;
	}
}
