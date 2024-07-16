/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:07:15 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/16 18:30:29 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	isber(char *file)
{
	int				len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strcmp(file + len - 4, ".ber") != 0)
		return (0);
	return (1);
}

int	main(int ac, char *av[])
{
	t_root			*root;

	if (ac != 2)
		exit_with_error("invalid number of arguments", 0);
	if (isber(av[1]) == 0)
		exit_with_error("invalid argument (<name>.ber)", 0);
	root = root_init(av[1]);
	render_frame(root);
	mlx_hook(root->mlx_win, 2, 1L << 0, handle_key_press, root);
	mlx_hook(root->mlx_win, 3, 1L << 1, handle_key_release, root);
	mlx_hook(root->mlx_win, 17, 1L << 17, handle_destroy_hook, root);
	mlx_loop(root->mlx);
	return (0);
}
