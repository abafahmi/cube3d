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
    int x = 0;
    int y = 0;

    while(l_map[x])
    {
        while (l_map[x][y])
        {
            if (l_map[x][y] == 'E' || l_map[x][y] == 'S'
            || l_map[x][y] == 'N' || l_map[x][y] == 'W')
            {
                mlx->p_x = x;
                mlx->p_y = y;
                break;
            }
            y++;
        }
        x++;
    }
}

void draw_map(char **l_map, t_mlx *mlx)
{
    int tile = TILE;
    int color = 0;
    int y = 0;
    int x = 0;
    while (l_map[x])
    {
        while(l_map[x][y])
        {
            if (l_map[x][y] == '1')
                color = 0xFF0000;
            else if (l_map[x][y] == '0')
                color = 0x000000;
            else
                color = 0xFFFFFF;
            mlx_pixel_put(mlx->mlx, mlx->window, x * tile, y * tile, color);
            y++;
        }
        x++;
    }
}

int handle_key(int key, t_mlx *mlx)
{
    if (key == 65307)
        exit(0);
    else if (key == 119 && map_bondries())
        mlx->p_y--;
    else if (key == 115)
        mlx->p_y++;
    else if (key == 97)
        mlx->p_x--;
    else if (key == 100)
        mlx->p_x++;

    mlx_clear_window(mlx->mlx, mlx->window);
    draw_map(mlx->l_map, mlx);

    return 0;
}

void mlx_func(char **l_map, t_mlx *mlx)
{   
    mlx->mlx = mlx_init();
    if (!mlx->mlx)
        mlx_error("mlx_int faild", mlx, l_map);
    mlx->window = mlx_new_window(mlx->mlx, WIN_COLS, WIN_ROWS, "cube3d_Cucurella");
    if (!mlx->window)
        mlx_error("mlx_new_window faild", mlx, l_map);
    mlx->l_map = l_map;
    get_palyer_xy(l_map, mlx);
    draw_map(l_map, mlx);
    mlx_key_hook(mlx->window, handle_key, mlx);
    mlx_loop(mlx->mlx);
}
