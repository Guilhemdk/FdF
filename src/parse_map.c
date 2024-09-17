/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:00:31 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/09/17 12:00:32 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_coords	**parse_map(char *filename, t_fdf *data)
{
	t_coords	**map;
	int			fd;

	fd = open(filename, O_RDONLY);
	map = malloc_map(filename, data);
	set_coordinates(fd, &map, &data);
	close(fd);
	return (map);
}

int	get_coordinates(char *line, t_coords **map, t_fdf *data, int y)
{
	char	**matrix;
	int		x;

	matrix = ft_split(line, ' ');
	x = 0;
	while (matrix[x])
	{
		map[y][x].z = ft_atoi(matrix[x]);
		map[y][x].x = x;
		map[y][x].y = y;
		map[y][x].color = get_colors(matrix[x]);
		map[y][x].last = 0;
		if (map[y][x].z > data->high)
			data->high = map[y][x].z;
		else if (map[y][x].z < data->low)
			data->low = map[y][x].z;
		free(matrix[x++]);
	}
	free(matrix);
	map[y][--x].last = 1;
	return (x);
}

static int	get_rows(char *line, int fd)
{
	int	y;

	y = 0;
	while (line)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (y);
}

t_coords	**malloc_map(char *filename, t_fdf *data)
{
	t_coords	**new;
	int			fd;
	int			x;
	int			y;
	char		*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		free_and_error(data, FILE_ERROR);
	line = get_next_line(fd);
	if (!line)
		free_and_error(data, INVALID_MAP);
	x = get_columns(line, ' ');
	y = get_rows(line, fd);
	new = (t_coords **)malloc(sizeof(t_coords *) * (++y + 1));
	if (!new)
		free_and_error(data, MALLOC_ERROR);
	while (y > 0)
	{
		new[--y] = (t_coords *)malloc(sizeof(t_coords) * (x + 1));
		if (!new[y])
			free_and_error(data, MALLOC_ERROR);
	}
	close(fd);
	return (new);
}

int	get_columns(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}
