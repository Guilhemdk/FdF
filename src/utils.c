/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:52:59 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/09/17 12:19:12 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double	get_scale(t_fdf *data)
{
	if (data->map_largeness < 100)
		return (3);
	if (data->map_largeness < 200)
		return (1.5);
	if (data->map_largeness < 400)
		return (1);
	if (data->map_largeness < 500)
		return (0.5);
	if (data->map_largeness < 700)
		return (0.4);
	if (data->map_largeness < 900)
		return (0.3);
	return (0.2);
}

double	get_z_scale(t_fdf *data)
{
	if (data->map_largeness < 50)
		return (1.3);
	if (data->map_largeness < 100)
		return (1);
	if (data->map_largeness < 300)
		return (0.5);
	if (data->map_largeness < 500)
		return (0.4);
	if (data->map_largeness < 700)
		return (0.3);
	if (data->map_largeness < 900)
		return (0.2);
	return (0.1);
}

double	abs_float(double x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
	return (0);
}

double	maximum(double x, double y)
{
	if (x > y)
		return (x);
	else
		return (y);
	return (0);
}

void	pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < img->line_length / (img->bits_per_pixel / 8) && y >= 0
		&& y < img->line_length / (img->bits_per_pixel / 8))
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}
