/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:03:20 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/17 01:05:15 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_with_error(char *error_msg, int error_num)
{
	if (error_msg != 0 || error_num != 0)
		ft_putendl_fd("Error", 2);
	if (error_msg != 0)
		ft_putstr_fd(error_msg, 2);
	if (error_msg != 0 && error_num != 0)
		ft_putstr_fd(": ", 2);
	if (error_num != 0)
		ft_putstr_fd(strerror(error_num), 2);
	if (error_msg != 0 || error_num != 0)
	{
		ft_putendl_fd("", 2);
		exit(1);
	}
	exit(0);
}
