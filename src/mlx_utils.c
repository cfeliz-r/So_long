/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:07:55 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/07/26 20:35:13 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	mlx_get_pixel(t_img *img, int pixel_x, int pixel_y)
{
	return (*(unsigned int *)
		(img->data + (pixel_x * img->bpp / 8 + pixel_y * img->size_line)));
}

void	mlx_draw_pixel(t_img *img, int pixel_x, int pixel_y, int pixel_color)
{
	char	*target;

	target = img->data + (pixel_x * img->bpp / 8 + pixel_y * img->size_line);
	*(unsigned int *)target = pixel_color;
}

unsigned int	mlx_rgb_to_int(int opacity, int red, int green, int blue)
{
	return (opacity << 24 | red << 16 | green << 8 | blue);
}
