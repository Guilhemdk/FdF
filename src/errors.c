/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:01:27 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/09/17 12:01:28 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	error(const char *err)
{
	size_t	i;

	i = 0;
	while (err[i])
	{
		write(2, &err[i], 1);
		i++;
	}
	exit(EXIT_FAILURE);
}

void	free_coords(t_coords **map, int rows)
{
	int	i;

	i = -1;
	if (map)
	{
		while (++i < rows)
			free(map[i]);
		free(map);
	}
}

void	free_and_error(t_fdf *data, char *msg)
{
	if (data)
	{
		if (data->map)
			free_coords(data->map, data->rows);
		if (data->image.img)
		{
			mlx_destroy_image(data->mlx_ptr, data->image.img);
			data->image.img = NULL;
		}
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		if (data->mlx_ptr)
			free(data->mlx_ptr);
		free(data);
	}
	error(msg);
}

int	correct_format(const char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i >= 0 && s[i] != '.')
		i--;
	return (i >= 0 && !ft_strncmp(s + i + 1, "fdf", 3));
}
