#include "../inc/fdf.h"

int coor_x(double x, t_fdf *data)
{
    if ((int)round(x) >= data->win_x)
        return ((int) x);
    return ((int) round(x));
}

int coor_y(double y, t_fdf *data)
{
    if ((int)round(y) >= data->win_y)
        return ((int) y);
    return ((int) round(y));
}

void pixel_put(t_image *img, int x, int y, int color)
{
    if (x >= 0 && x < img->line_length / (img->bits_per_pixel / 8) && 
        y >= 0 && y < img->line_length / (img->bits_per_pixel / 8))
    {
        char *dst;

        dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
        *(unsigned int *)dst = color;
    }
}

