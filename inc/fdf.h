#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "fdf_structs.h"
# include "macros.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"


void error(const char *err);
void free_coords(t_coords **map, int rows);
void free_and_error(t_fdf *data, char *msg);
int close_program(t_fdf *data);

int correct_format(const char *s);
int get_columns(char *str, char c);
t_coords **malloc_map(char *filename, t_fdf *data);
t_coords **parse_map(char *filename, t_fdf *data);
int get_coordinates(char *line, t_coords **map, t_fdf *data, int y);

double get_scale(t_fdf *data);
double get_z_scale(t_fdf *data);
double abs_float(double x);
double maximum(double x, double y);

int get_index(char *hex, char c);
int hex_to_int(char *s);
int get_colors(char * s);
int look_for_colors(t_coords **map);

void draw_map(t_coords **map, t_fdf *data);

int  color_level(double perc);
double   percent(int start, int end, int current);
int smoothen_color(t_coords current, t_coords start, t_coords end);
void    z_color_level(t_fdf *data);

void    reset(t_fdf *data);
void pixel_put(t_image *img, int x, int y, int color);
int coor_y(double y, t_fdf *data);
int coor_x(double x, t_fdf *data);

int generate_event(int key, t_fdf *data);

#endif
