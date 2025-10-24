#include "cub3d.h"

void mlx_error(char *msg, t_mlx *mlx, char **l_map)
{
    printf("%s", msg);
    if (mlx->mlx)
		mlx_destroy_display(mlx->mlx);
    free_cube(l_map, mlx);
}

void    get_x_and_y(char **l_map, t_mlx *mlx)
{
    int i = 0;
    int size = 0;

    while(l_map[i])
    {
        int size_next = (int)ft_strlen(l_map[i]);
        if (size < size_next)
            size = size_next;
        i++;
    }
    mlx->x = i;
    mlx->y = size;
}

void mlx_func(char **l_map, t_mlx *mlx)
{
    int x = 0;
    int y;
    int px, py;
    int color;
    int tile_size = 34;
    
    mlx->mlx = mlx_init();
    if (!mlx->mlx)
        mlx_error("mlx_int faild", mlx, l_map);
    mlx->window = mlx_new_window(mlx->mlx, 20 * 34, 15 * 34, "cube3d_Cucurella");
    if (!mlx->window)
        mlx_error("mlx_new_window faild", mlx, l_map);
    get_x_and_y(l_map, mlx);
    while (x < mlx->x)
    {
        y = 0;
        while (y < mlx->y)
        {
            if (l_map[y][x] == 1)
                color = 0xFF0000; // red
            else
                color = 0x0000FF; // blue
            py = 0;
            while (py < tile_size)
            {
                px = 0;
                while (px < tile_size)
                {
                    mlx_pixel_put(mlx->mlx, mlx->window, x * tile_size + px, y * tile_size + py, color);
                    px++;
                }
                py++;
            }
            y++;
        }
        x++;
    }
    mlx_loop(mlx->mlx);
}
