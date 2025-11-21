#include "cub3d.h"

void draw_s(t_mlx *mlx, unsigned int color, int x, int y)
{
    int i = 0;
    int j;

    if (x < 0)
        x *= -1;
    if (y < 0)
        y *= -1;
    while (i <= WIN_ROWS / mlx->map_bx)
    {
        j = 0;
        while (j <= WIN_ROWS / mlx->map_by)
        {
            my_mlx_pixel_put(mlx, y * WIN_ROWS / mlx->map_by + j, x * WIN_ROWS / mlx->map_bx + i, color);
            j++;
        }
        i++;
    }
}

void draw_sandrp(t_mlx *mlx, unsigned int color, int xi, int yi)
{
    double i = 0;
    double x = (double)xi;
    double y = (double)yi;
    while (y > 0 && mlx->l_map[(int)x][(int)y] && mlx->l_map[(int)x][(int)y] != '1')
    {
        i = 0;
        while (i < 30)
        {
             my_mlx_pixel_put(mlx, y * WIN_ROWS / mlx->map_by, x * WIN_ROWS / mlx->map_bx + i, color);
             i += 0.1;
        }
        y--;
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
            {
                color = 0xFF0000;
                draw_sandrp(mlx, color, x, y);
                y++;
                continue;
            }
            else if (l_map[x][y] == '1')
                color = 0x0000FF;
            else if (l_map[x][y] == '0')
                color = 0x00FF00;
            else
                color = 0x000000;
            draw_s(mlx, color, x, y);
            y++;
        }
        x++;
    }
}

void map_b_y(char **map, t_mlx *mlx)
{
    int i = 0, j;
    int max = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (j > max)
                max = j;
            j++;
        }
        i++;
    }
    mlx->map_bx = i;
    mlx->map_by = max;
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
            {
                color = 0x0000FF;
            }
            else if (l_map[x][y] == '0')
            color = 0x00FF00;
            else if (l_map[x][y] == 'N')
            color = 0xFF0000;
            else
                color = 0x000000;
            draw_s(mlx, color, x, y);
            y++;
        }
        x++;
    }
}

int	g_y(int y)
{
	static int	value = 0;

	if (y == -1)
		return (value);
	value = y;
	return (value);
}

int	g_x(int x)
{
	static int	value = 0;

	if (x == -1)
		return (value);
	value = x;
	return (value);
}
/*
void    draw_mapcam(char **l_map, t_mlx *mlx)
{
    int i = mlx->cam_x;
    int j = mlx->cam_y;
    unsigned int color = 0;
   
    if (i <= -1)
        i = 0;
    if (j <= -1)
        j = 0;
    while (l_map[i])
    {
        j = mlx->cam_y;
        if (j <= -1)
            j = 0;
        while (l_map[i][j])
        {
            if (i == mlx->p_x && j == mlx->p_y)
                color = 0xFF0000;
            else if (l_map[i][j] == '1')
                color = 0x0000FF;
            else if (l_map[i][j] == '0')
                color = 0x00FF00;
            else
                color = 0x000000;
            draw_s(mlx, color, mlx->cam_x - i, mlx->cam_y - j);
            j++;
        }
        i++;
    }
}*/