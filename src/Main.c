/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:01:01 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/09/17 12:01:02 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	get_map_largerness(t_coords **map, t_fdf *data)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (!map[y][x].last)
		x++;
	data->columns = x;
	while (map[y])
		y++;
	data->rows = y;
	return (y + x);
}

void	init_fdfstruct(t_fdf *data, char *filename)
{
	data->high = INT_MIN;
	data->low = INT_MAX;
	data->map = parse_map(filename, data);
	data->map_largeness = get_map_largerness(data->map, data);
	data->scale = get_scale(data) * 25;
	data->z_scale = get_z_scale(data);
	data->is_isometric = 1;
	data->angle = 0.663599;
	data->win_x = WIN_WIDTH;
	data->win_y = WIN_HEIGHT;
	data->shift_x = data->win_x / 4;
	data->shift_y = data->win_y / 4;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		free_and_error(data, MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_x, data->win_y,
			"FdF Project");
	if (!data->win_ptr)
		free_and_error(data, MLX_ERROR);
	data->has_colors = look_for_colors(data->map);
	z_color_level(data);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		error(INPUT_ERROR);
	else if (!correct_format(argv[1]))
		error(FORMAT_ERROR);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		error(MALLOC_ERROR);
	init_fdfstruct(data, argv[1]);
	data->image.img = mlx_new_image(data->mlx_ptr, data->win_x, data->win_y);
	if (!data->image.img)
		free_and_error(data, IMG_ERROR);
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel, &data->image.line_length,
			&data->image.endian);
	draw_map(data->map, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, generate_event, data);
	mlx_loop(data->mlx_ptr);
}
