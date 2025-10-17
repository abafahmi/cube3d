#include "cub3d.h"

char	*free_strjoin(char *line, char *map)
{
	char	*holder;

	holder = ft_strjoin(line, map);
	if (!holder)
	{
		free(holder);
		exit(1);
	}
	free(line);
	return (holder);
}

void free_cube(char **l_map, t_mlx *mlx)
{
	if (mlx->floor_color)
		free(mlx->floor_color);
	if (mlx->sky_color)
		free(mlx->sky_color);
	free_all(l_map);
	free(mlx);
	exit(1);
}

void	check_map_name(char *str)
{
	char	*s;

	s = ft_strrchr(str, '/');
	if (!s)
		ft_error("Error\n :) invalid name", NULL, NULL);
	else
	{
		if ((aaf_strnstr(s, ".cub")) == 0)
			ft_error("Error\n :) invalid name", NULL, NULL);
	}
}

void	check_map(char **av)
{
	int		f_map;
	char	*map;
	char	**l_map;
	char	*line;
	t_mlx	*mlx;

	mlx = ft_calloc(sizeof(t_mlx), 1);
	if (!mlx)
		ft_error("calloc failed", NULL, NULL);
	line = NULL;
	f_map = open (av[1], O_RDONLY, 0644);
	if (f_map == -1)
	{
		free(mlx);
		ft_error("Error\n :( FD", NULL, NULL);
	}
	map = get_next_line(f_map);
	if (!map)
	{
		free(mlx);
		ft_error("Error\n :) invalid map", NULL, NULL);
	}
	while (map != NULL)
	{
		line = free_strjoin(line, map);
		free(map);
		map = get_next_line(f_map);
	}
	l_map = ft_split(line, '\n');
	if (!l_map)
	{
		free(mlx);
		ft_error1("Error \n: !l_map", line);
	}
	free(line);
	if (check_the_diractions(l_map, &mlx) == false)
		free_cube(l_map, mlx);
	if (is_valid_map(l_map) == false)
		free_cube(l_map, mlx);
	mlx_func(l_map, mlx);
	printf("valid");
	free_cube(l_map, mlx);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        check_map_name(av[1]);
        check_map(av);
    }
    else
		ft_error("Error \n", NULL, NULL);
}