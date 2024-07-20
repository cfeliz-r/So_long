/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:20:32 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/20 18:19:40 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill(char **tab, t_coordinates size, t_coordinates pos, char target)
{
	t_coordinates	next_pos;

	if (pos.y < 0 || pos.x < 0 || pos.y >= size.y || pos.x >= size.x)
		return ;
	if (tab[pos.y][pos.x] == 'F' || tab[pos.y][pos.x] != target)
		return ;
	tab[pos.y][pos.x] = 'F';
	next_pos = (t_coordinates){pos.x, pos.y - 1};
	fill(tab, size, next_pos, target);
	next_pos = (t_coordinates){pos.x, pos.y + 1};
	fill(tab, size, next_pos, target);
	next_pos = (t_coordinates){pos.x - 1, pos.y};
	fill(tab, size, next_pos, target);
	next_pos = (t_coordinates){pos.x + 1, pos.y};
	fill(tab, size, next_pos, target);
}

static void	flood_fill(char **tab, t_coordinates size, t_coordinates begin)
{
	char	target;

	target = tab[begin.y][begin.x];
	fill(tab, size, begin, target);
}

static char	**duplicate_map(t_game_root *root)
{
	char	**dup;
	int		i;
	int		j;

	i = 0;
	dup = malloc(sizeof(char *) * root->game->map_height
			* root->game->map_width);
	if (!dup)
		return (NULL);
	while (i < root->game->map_height)
	{
		dup[i] = malloc(sizeof(char) * (root->game->map_width + 1));
		if (dup[i] == NULL)
		{
			while (i > 0)
				free(dup[--i]);
			free(dup);
			return (NULL);
		}
		j = -1;
		while (++j < root->game->map_width)
			dup[i][j] = root->game->game_map[i][j];
		dup[i++][root->game->map_width] = '\0';
	}
	return (dup);
}

static void	free_map_duplicate(char **map, int height)
{
	int		i;

	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}

int	is_accessible(t_game_root *root)
{
	char			**map_copy;
	int				i;
	t_coordinates	size;
	t_coordinates	start;

	size.x = root->game->map_width;
	size.y = root->game->map_height;
	map_copy = duplicate_map(root);
	start = find_starting_position(map_copy, size);
	flood_fill(map_copy, size, start);
	if (map_copy[root->game->exit_position.y]
		[root->game->exit_position.x] != 'F')
		return (free_map_duplicate(map_copy, size.y), 0);
	i = -1;
	while (++i < root->game->total_collectibles)
	{
		if (map_copy[root->game->collectibles[i].y]
			[root->game->collectibles[i].x] != 'F')
			return (free_map_duplicate(map_copy, size.y), 0);
	}
	if (map_copy[root->game->player_position.y]
		[root->game->player_position.x] != 'F')
		return (free_map_duplicate(map_copy, size.y), 0);
	return (free_map_duplicate(map_copy, size.y), 1);
}
