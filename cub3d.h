#ifndef CUB3D_H
#define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>

#define TILE 32
#define WIN_COLS 640
#define WIN_ROWS 480

typedef struct
{
    int r;
    int g;
    int b;
} t_rgb;

typedef struct
{
    t_rgb *floor_color;
    t_rgb *sky_color;
	char **l_map;
	void	*mlx;
	void	*window;
	int	cam_x;
	int cam_y;
	int p_x;
	int p_y;
	int map_h;
	int map_w;
} t_mlx;
/*
typedef struct s_mlx {
	t_rgb *floor_color;
    t_rgb *sky_color;
    void    *mlx;
    void    *window;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
    char    **l_map;
    int     cam_x;
    int     cam_y;
    int     map_h;
    int     map_w;
}   t_mlx;
*/
typedef struct
{
	int s;
	int w;
	int e;
	int n;
	int f;
	int c;

} t_dir;



t_rgb	*handle_rgb(char *str, char **l_map);
void	free_cube(char **l_map, t_mlx *mlx);
void	check_char(char *line);
void	ft_error1(char *msg, char *line);
void	ft_error(char *msg, char **str, char **s2);
void	mlx_func(char **l_map, t_mlx *mlx);
bool    is_valid_map(char **map);
bool	check_the_diractions(char **l_map, t_mlx **mlx);
int             free_all(char **str_array);
int             aaf_strnstr(char *big, char *little);
int             characters(int c);
int             diractions_f_c(char c);


#endif