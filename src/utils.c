/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:52:59 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/09/17 11:53:00 by gmiorcec         ###   ########.fr       */
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
