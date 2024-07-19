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

void	root_destroy(t_game_root *root, char *error_msg, int error_num)
{
	if (root != NULL)
	{
		if (root->ground != 0)
			mlx_destroy_image(root->mlx_instance, root->ground);
		if (root->wall != 0)
			mlx_destroy_image(root->mlx_instance, root->wall);
		if (root->collectible_image != 0)
			mlx_destroy_image(root->mlx_instance, root->collectible_image);
		if (root->exit_image != 0)
			mlx_destroy_image(root->mlx_instance, root->exit_image);
		if (root->player != 0)
			mlx_destroy_image(root->mlx_instance, root->player);
		if (root->mlx_img != 0)
			mlx_destroy_image(root->mlx_instance, root->mlx_img);
		if (root->mlx_window != 0)
			mlx_destroy_window(root->mlx_instance, root->mlx_window);
		if (root->mlx_instance != 0)
		{
			mlx_destroy_display(root->mlx_instance);
			free(root->mlx_instance);
			root->mlx_instance = 0;
		}
		if (root->game != NULL)
			free_game_resources(root->game);
		free(root);
	}
	exit_with_error(error_msg, error_num);
}
