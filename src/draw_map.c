#include "../inc/fdf.h"

void apply_zoom(t_coords *a, t_coords *b, t_fdf *data)
{
    a->x *= data->scale;
    a->y *= data->scale;
    b->x *= data->scale;
    b->y *= data->scale;
    a->z *= data->z_scale;
    b->z *= data->z_scale;
}

void    apply_iso(t_coords *axis, double angle)
{
    axis->x = (axis->x - axis->y) * cos(angle);
    axis->y = (axis->x + axis->y) * sin(angle) -axis->z;
}

void    transfo_coords(t_coords *a, t_coords *b, t_fdf *data)
{
    apply_zoom(a, b, data);
    if (data->is_isometric)
    {
        apply_iso(a, data->angle);
        apply_iso(b, data->angle);
    }
    a->x += data->shift_x;
    b->x += data->shift_x;
    a->y += data->shift_y;
    b->y += data->shift_y;
}

void draw_line(t_coords a, t_coords b, t_fdf *data)
{
    double step_x;
    double step_y;
    double max;
    t_coords current;

    transfo_coords(&a, &b, data);
    current.x = a.x;
    current.y = a.y;
    step_x = b.x - a.x;
    step_y = b.y - a.y;
    max = maximum(abs_float(step_x), abs_float(step_y));
    step_x /= max;
    step_y /= max;
    
    while((int)(current.x - b.x) || (int)(current.y - b.y))
    {
        if (current.x > data->win_x || current.y > data->win_y || current.y < 0 || current.x < 0)
            break;
        if (coor_x(current.x, data) < data->win_x && \
        coor_y(current.y, data) < data->win_y)
            pixel_put(&data->image, coor_x(current.x, data), \
            coor_y(current.y, data), smoothen_color(current, a, b));
        current.x += step_x;
        current.y += step_y;
    }
    if (coor_x(b.x, data) < data->win_x && \
    coor_y(b.y, data) < data->win_y)
        pixel_put(&data->image, coor_x(b.x, data), \
        coor_y(b.y, data), smoothen_color(b, a, b));
}


void image_to_window(t_fdf *data)
{
    if (data->image.img)
    {
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.img, 0, 0);
        mlx_destroy_image(data->mlx_ptr, data->image.img);
    }
    data->image.img = mlx_new_image(data->mlx_ptr, data->win_x, data->win_y);
    if (!data->image.img)
        free_and_error(data, IMG_ERROR);
    data->image.addr = mlx_get_data_addr(data->image.img, &data->image.bits_per_pixel,
                                         &data->image.line_length, &data->image.endian);
}



void draw_map(t_coords **map, t_fdf *data)
{
    int y;
    int x;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (1)
        {
            if(map[y + 1])
                draw_line(map[y][x], map[y + 1][x], data);
            if(!map[y][x].last)
                draw_line(map[y][x], map[y][x + 1], data);
            else
                break ;
            x++;
        }
        y++;
    }
    image_to_window(data);
}
