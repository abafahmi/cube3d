#include "cub3d.h"

void draw_s(t_mlx *mlx, unsigned int color, int x, int y)
{
    int i = 0;
    int j;
    while (i < TILE)
    {
        j = 0;
        while (j < TILE)
        {
            mlx_pixel_put(mlx->mlx, mlx->window, y * TILE + j, x * TILE + i, color);
            j++;
        }
        i++;
    }
}

void draw_mapv2(char **l_map, t_mlx *mlx)
{
    unsigned int  color = 0;
    int y;
    int x = 0;
    while (l_map[x])
    {
        y = 0;
        while(l_map[x][y])
        {
            if (x == mlx->p_x && y == mlx->p_y)
                color = 0xFF0000;
            else if (l_map[x][y] == '1')
                color = 0x0000FF;
            else if (l_map[x][y] == '0')
                color = 0x00FF00;
            draw_s(mlx, color, x, y);
            y++;
        }
        x++;
    }
}

void draw_map(char **l_map, t_mlx *mlx)
{
    unsigned int  color = 0;
    int y;
    int x = 0;
    while (l_map[x])
    {
        y = 0;
        while(l_map[x][y])
        {
            if (l_map[x][y] == '1')
                color = 0x0000FF;
            else if (l_map[x][y] == '0')
                color = 0x00FF00;
            else if (l_map[x][y] == 'N')
                color = 0xFF0000;
            draw_s(mlx, color, x, y);
            y++;
        }
        x++;
    }
}

void    draw_mapcam(char **l_map, t_mlx *mlx, int i, int y)
{
    unsigned int  color = 0;
    int y;
    int x = 0;
    while (l_map[x])
    {
        y = 0;
        while(l_map[x][y])
        {
            if (l_map[x][y] == '1')
                color = 0x0000FF;
            else if (l_map[x][y] == '0')
                color = 0x00FF00;
            else if (l_map[x][y] == 'N')
                color = 0xFF0000;
            draw_s(mlx, color, x, y);
            y++;
        }
        x++;
    }
}