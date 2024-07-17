/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:06:41 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/16 17:06:42 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	root_destroy(t_root *root, char *error_msg, int error_num)
{
	if (root != 0)
	{
		if (root->ground != 0)
			mlx_destroy_image(root->mlx, root->ground);
		if (root->wall != 0)
			mlx_destroy_image(root->mlx, root->wall);
		if (root->coll != 0)
			mlx_destroy_image(root->mlx, root->coll);
		if (root->exit_image != 0)
			mlx_destroy_image(root->mlx, root->exit_image);
		if (root->player != 0)
			mlx_destroy_image(root->mlx, root->player);
		if (root->mlx_img != 0)
			mlx_destroy_image(root->mlx, root->mlx_img);
		if (root->mlx_win != 0)
			mlx_destroy_window(root->mlx, root->mlx_win);
		if (root->mlx != 0)
			mlx_destroy_display(root->mlx);
		if (root->game != 0)
			free_game_resources(root->game);
		free(root);
	}
	exit_with_error(error_msg, error_num);
}
