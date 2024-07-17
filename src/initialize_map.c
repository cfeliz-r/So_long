/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:05:03 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/17 13:02:37 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	file_parse(t_root *root, char **file, char buf[], int fd)
{
	char			*tmp;

	tmp = ft_strjoin(*file, buf);
	free(*file);
	*file = tmp;
	if (*file == 0)
	{
		close(fd);
		root_destroy(root, "initialize_map(): ft_strjoin()", errno);
	}
}

static void	file_read(t_root *root, char **file, char buf[], int fd)
{
	int				ret;

	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buf, 1024);
		if (ret == -1)
		{
			free(*file);
			close(fd);
			root_destroy(root, "initialize_map(): read()", errno);
		}
		else
		{
			buf[ret] = 0;
			file_parse(root, file, buf, fd);
		}
	}
}

static char	*file_init(t_root *root, int fd)
{
	char			*file;

	file = ft_calloc(1, 1);
	if (file == 0)
	{
		close(fd);
		root_destroy(root, "initialize_map(): ft_calloc()", errno);
	}
	return (file);
}

static void	read_map_file(t_root *root, char *file)
{
	map_width(root, file);
	calculate_map_height(root, file);
	map_isvalid(root, file);
	root->game->collectibles_positions
		= (t_coordinates *)malloc(sizeof(t_coordinates) * root->game->count_coll);
	if (root->game->collectibles_positions == 0)
	{
		free(file);
		root_destroy(root, "map_parsing(): malloc()", errno);
	}
	root->game->map = (int **)malloc(sizeof(int *) * root->game->height);
	if (root->game->map == 0)
	{
		free(file);
		root_destroy(root, "map_parsing(): malloc()", errno);
	}
	map_parsing(root, file);
}

void	initialize_map(t_root *root, char *filename)
{
	int				fd;
	char			*file;
	char			buf[1024 + 1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		root_destroy(root, filename, errno);
	file = file_init(root, fd);
	file_read(root, &file, buf, fd);
	close(fd);
	read_map_file(root, file);
	free(file);
}
