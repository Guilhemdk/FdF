/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:54:13 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/09/17 11:54:14 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	color_level(double perc)
{
	if (perc < 0.1)
		return (COLOR_ONE);
	else if (perc < 0.2)
		return (COLOR_TWO);
	else if (perc < 0.3)
		return (COLOR_THREE);
	else if (perc < 0.4)
		return (COLOR_FOUR);
	else if (perc < 0.5)
		return (COLOR_FIVE);
	else if (perc < 0.6)
		return (COLOR_SIX);
	else if (perc < 0.7)
		return (COLOR_SEVEN);
	else if (perc < 0.8)
		return (COLOR_EIGHT);
	else if (perc < 0.9)
		return (COLOR_NINE);
	else
		return (COLOR_TEN);
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

void	z_color_level(t_fdf *data)
{
	int		i;
	int		j;
	double	percentage;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j <= data->columns)
		{
			if (data->map[i][j].color == -1)
			{
				percentage = percent(data->low, data->high, data->map[i][j].z);
				data->map[i][j].color = color_level(percentage);
			}
			j++;
		}
		i++;
	}
}

static int	radiant(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	smoothen_color(t_coords current, t_coords start, t_coords end)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (start.color == end.color)
		return (start.color);
	if (abs_float(end.x - start.x) > abs_float(end.y - start.y))
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = radiant((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF,
			percentage);
	green = radiant((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF,
			percentage);
	blue = radiant(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
