#include "../inc/fdf.h"

void    reset(t_fdf *data)
{
    data->scale = get_scale(data) * 25;
    data->z_scale = get_z_scale(data);
    data->angle = 0.563599;
    data->shift_x = data->win_x / 3;
    data->shift_y = data->win_y / 3;
}

void    zoom_events(int key, t_fdf *data)
{
    if (key == 112)
        data->scale += get_scale(data);
    if (key == 109)
        data->scale -= get_scale(data);
    if (key == 45)
        data->z_scale -= get_z_scale(data);
    if(key == 61)
        data->z_scale += get_z_scale(data);
}

void handle_key(int key, t_fdf *data)
{
    zoom_events(key, data);
    if (key == 65307)
		close_program(data);
    if (key == 65363)
        data->shift_x -= 10;
    if (key == 65364)
        data->shift_y -= 10;
    if (key == 65361)
        data->shift_x += 10;
    if (key == 65362)
        data->shift_y += 10;
    if (key == 32)
        data->angle -= 0.07;
    if(key == 65288)
        data->angle += 0.07;
    if(key == 65293)
        reset(data);
}

int is_key(int key)
{
    return (key == 65361 || key == 65362 || key == 65363 || key == 65364 || \
    key == 112 || key == 109 || key == 45 ||key == 61 || key == 65307 || \
    key == 32 ||key == 65288 || key == 65293);
}

int generate_event(int key, t_fdf *data)
{
    if(is_key(key))
    {
        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        handle_key(key, data);
        draw_map(data->map, data);
    }
    return (0);
}
