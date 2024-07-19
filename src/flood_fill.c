/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:20:32 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/19 16:13:29 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill(char **tab, t_coordinates size, char target, int row, int col)
{
    if (row < 0 || col < 0 || row >= size.y || col >= size.x)
        return ;
    if (tab[row][col] == 'F' || tab[row][col] != target)
        return ;
    
    tab[row][col] = 'F';
    fill(tab, size, target, row - 1, col);
    fill(tab, size, target, row + 1, col);
    fill(tab, size, target, row, col - 1);
    fill(tab, size, target, row, col + 1);
}

static void flood_fill(char **tab, t_coordinates size, t_coordinates begin)
{
    char    target;

    target = tab[begin.y][begin.x];
    fill(tab, size, target, begin.y, begin.x);
}

static char **duplicate_map(t_game_root *root)
{
    char    **dup;
    int     i;
    int     j;

    i = 0;
    dup = malloc(sizeof(char *) * root->game->map_height);
    if(!dup)
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
        j = 0;
        while (j < root->game->map_width)
        {
            dup[i][j] = root->game->game_map[i][j] + '0';
            j++;
        }
        dup[i++][root->game->map_width] = '\0';
    }
    return (dup);
}
static void free_map_duplicate(char **map, int height)
{
    int     i;
    
    i = 0;
    while (i < height)
        free(map[i++]);
    free(map);
}

int is_accessible(t_game_root *root)
{
    char    **map_copy;
    int     i;

    map_copy = duplicate_map(root);
    t_coordinates size = {root->game->map_width, root->game->map_height};
    t_coordinates start = {root->game->player_position.y, root->game->player_position.x};
    flood_fill(map_copy, size, start);
    if (map_copy[root->game->exit_position.y][root->game->exit_position.x] != 'F')
    {
        free_map_duplicate(map_copy, root->game->map_height);
        return (0);
    }
    i = 0;
    while (i < root->game->total_collectibles)
    {
        if (map_copy[root->game->collectibles_positions[i].y][root->game->collectibles_positions[i].x] != 'F')
        {
            free_map_duplicate(map_copy, root->game->map_height);
            return(0);
        }
        i++;
    }
    if (map_copy[root->game->player_position.y][root->game->player_position.x] != 'F')
    {
        free_map_duplicate(map_copy, root->game->map_height);
        return (0);
    }
    free_map_duplicate(map_copy, root->game->map_height);
    return (1);
}
