/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_handler_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:24:46 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/13 13:24:48 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_count(char *line, int fd)
{
	int	i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	free(line);
	return (i);
}

char	**map_fill(int fd, char *line, t_data *mlx)
{
	int		i;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (mlx->lines + 1));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	map[i] = 0;
	return (map);
}

void	player_coordinates(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	mlx->p_x = 0;
	mlx->p_y = 0;
	while (i < mlx->lines)
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (check_for_players(mlx, mlx->map[i][j]))
			{
				mlx->p_y = i;
				mlx->p_x = j;
			}
			if (mlx->map[i][j] == 'E')
				mlx->exits++;
			if (mlx->map[i][j] == 'C')
				mlx->total_collectibles++;
			j++;
		}
		i++;
	}
	return ;
}

int	check_wall(t_data *mlx, char flag)
{
	if (flag == 'W' && ((mlx->map[mlx->p_y - 1][mlx->p_x]) == '1'
		|| (((mlx->map[mlx->p_y - 1][mlx->p_x]) == 'E')
		&& (mlx->caught_collectibles != mlx->total_collectibles))))
		return (0);
	if (flag == 'A' && ((mlx->map[mlx->p_y][mlx->p_x - 1]) == '1'
		|| (((mlx->map[mlx->p_y][mlx->p_x - 1]) == 'E')
		&& (mlx->caught_collectibles != mlx->total_collectibles))))
		return (0);
	if (flag == 'S' && ((mlx->map[mlx->p_y + 1][mlx->p_x]) == '1'
		|| (((mlx->map[mlx->p_y + 1][mlx->p_x]) == 'E')
		&& (mlx->caught_collectibles != mlx->total_collectibles))))
		return (0);
	if (flag == 'D' && ((mlx->map[mlx->p_y][mlx->p_x + 1]) == '1'
		|| (((mlx->map[mlx->p_y][mlx->p_x + 1]) == 'E')
		&& (mlx->caught_collectibles != mlx->total_collectibles))))
		return (0);
	return (1);
}

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
