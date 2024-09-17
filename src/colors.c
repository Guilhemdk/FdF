#include "../inc/fdf.h"

int get_index(char *hex, char c)
{
    int i;

    i = 0;
    while(hex[i])
    {
        if (hex[i] == c)
            return (i);
        i++;
    }
    return (0);
}

int hex_to_int(char *s)
{
    char *hex;
    int i;
    int res;

    hex = "0123456789abcdef";
    res = 0;
    i = 0;
    while(s[i])
    {
        res = res * 16 + get_index(hex, ft_tolower(s[i]));
        i++;
    }
    return (res);
}

int get_colors(char * s)
{
    int i;

    i = 0;
    while(s[i] && s[i] != ',')
        i++;
    if (!s[i])
        return (-1);
    return (hex_to_int(s + i + 2));
}

int look_for_colors(t_coords **map)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(!map[i][j].last)
        {
            if(map[i][j].color != -1)
                return(1);
            j++;
        }
        i++;
    }
    return (0);
}
