/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:15:55 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/09/17 12:15:56 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

typedef struct s_coords
{
	double		x;
	double		y;
	int			z;
	int			color;
	int			last;
}		t_coords;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_image;

typedef struct s_fdf
{
	int			map_largeness;
	int			high;
	int			low;
	int			columns;
	int			rows;
	double		scale;
	double		z_scale;
	int			win_x;
	int			win_y;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			has_colors;
	void		*mlx_ptr;
	void		*win_ptr;
	t_coords	**map;
	t_image		image;
}		t_fdf;

#endif
