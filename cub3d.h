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
} t_mlx;

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
void	check_char(char *line);
void	ft_error1(char *msg, char *line);
void	ft_error(char *msg, char **str, char **s2);
bool    is_valid_map(char **map);
bool	check_the_diractions(char **l_map, t_mlx **mlx);
int             free_all(char **str_array);
int             aaf_strnstr(char *big, char *little);
int             characters(int c);
int             diractions_f_c(char c);


#endif