/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:01:39 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/09/17 12:01:40 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	close_program(t_fdf *data)
{
	if (data->image.img)
	{
		mlx_destroy_image(data->mlx_ptr, data->image.img);
		data->image.img = NULL;
	}
	if (data->map)
		free_coords(data->map, data->rows);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr)
	{
		free(data->mlx_ptr);
	}
	free(data);
	exit(EXIT_SUCCESS);
}
