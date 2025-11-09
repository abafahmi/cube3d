#include "cub3d.h"

// static void	set_pixel_color(int x, int y, int color, t_mlx *mlx)
// {
// 	int	pixel_offset;

// 	pixel_offset = y * mlx->line + x * (mlx->bpp / 8);
// 	*(unsigned int *)(mlx->data + pixel_offset) = color;
// }

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
        y = 0;
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

void clear(t_mlx *mlx)
{
    int i = 0;
    int j;
    while (i < WIN_COLS)
    {
        j = 0;
        while (j < WIN_ROWS)
        {
            mlx_pixel_put(mlx->mlx, mlx->window, i, j, 0);
            j++;
        }
        i++;
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

void get_palyer_xy(char **l_map, t_mlx *mlx)
{
    int i = 0;
    int j = 0;
    while (l_map[i])
    {
        j = 0;
            // printf("wtf\n");
        while (l_map[i][j])
        {
            // printf("wtf\n");
            if (l_map[i][j] == 'W' || l_map[i][j] == 'E'
                || l_map[i][j] == 'S' || l_map[i][j] == 'N')
            {
                mlx->p_x = i;
                mlx->p_y = j;
                //printf("i = %d , j = %d\n", i,j);
                return ;
            }
            j++;
        }
        i++;
    }
}

int map_boundries(t_mlx *mlx, int i)
{
    if (i == 0)
    {
        if (mlx->l_map[mlx->p_x - 1][mlx->p_y] == '1')
            return (1);
    }
    else if (i == 1)
    {
        if (mlx->l_map[mlx->p_x + 1][mlx->p_y] == '1')
            return (1);
    }
    else if (i == 2)
    {
        if (mlx->l_map[mlx->p_x][mlx->p_y - 1] == '1')
            return (1);
    }
    else
    {
        if (mlx->l_map[mlx->p_x][mlx->p_y + 1] == '1')
            return (1);
    }
    return (0);
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
/*void    handle_cam(int key, t_mlx *mlx)
{
    if (key == 119)
        mlx->cam_x--;
    else if (key == 97)
        mlx->cam_y--;
    else if (key == 115)
        mlx->cam_x++;
    else if (key == 100)
        mlx->cam_y++;
}*/

int handle_key(int key, t_mlx *mlx)
{
    if (key == 65307)
        exit(0);
    else if (key == 65363 && map_boundries(mlx, RIGHT) == 0) 
        mlx->p_y++;
    else if (key == 65361 && map_boundries(mlx, LEFT) == 0)
        mlx->p_y--;
    else if (key == 65364 && map_boundries(mlx, DOWN) == 0)
        mlx->p_x++;
    else if (key == 65362 && map_boundries(mlx, UP) == 0)
        mlx->p_x--;
    //else
        //handle_cam(key, mlx);
    clear(mlx);
    draw_mapv2(mlx->l_map, mlx);
    return 0;
}

int render(t_mlx *mlx)
{
    clear(mlx);
    draw_map(mlx->l_map, mlx);
    return (0);
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
   // mlx_loop_hook(mlx->mlx, &render, &mlx);
    mlx_key_hook(mlx->window, handle_key, mlx);
    mlx_loop(mlx->mlx);
}
