/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:53:57 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/09/17 12:02:48 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	coor_x(double x, t_fdf *data)
{
	if ((int)round(x) >= data->win_x)
		return ((int)x);
	return ((int)round(x));
}

int	coor_y(double y, t_fdf *data)
{
	if ((int)round(y) >= data->win_y)
		return ((int)y);
	return ((int)round(y));
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

void set_coordinates(int fd, t_coords *map, t_fdf *data)
{
	char *line;
	int y;

	if (fd < 0)
		error(FILE_ERROR);
	y = 0;
	line = get_next_line(fd);
	if (!line)
		error(INVALID_MAP);
	while (line)
	{
		get_coordinates(line, map, data, y++);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (map[y])
		free(map[y]);
	map[y] = NULL;
}
void	apply_zoom(t_coords *a, t_coords *b, t_fdf *data)
{
	a->x *= data->scale;
	a->y *= data->scale;
	b->x *= data->scale;
	b->y *= data->scale;
	a->z *= data->z_scale;
	b->z *= data->z_scale;
}

void	apply_iso(t_coords *axis, double angle)
{
	axis->x = (axis->x - axis->y) * cos(angle);
	axis->y = (axis->x + axis->y) * sin(angle) - axis->z;
}