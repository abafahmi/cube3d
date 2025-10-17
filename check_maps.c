#include "cub3d.h"

int	characters(int c)
{
	return (c == '1' || c == '0'
		|| c == 'E' || c == 'S'
		|| c == 'N' || c == ' ' || c == 'W' || c == '\n');
}

int diractions_f_c(char c)
{
	return (c == 'S' || c == 'W' || c == 'E'
		|| c == 'N' || c == 'F' || c == 'C');
}

void init_dir(t_dir *d)
{
	d->e = 0;
	d->n = 0;
	d->s = 0;
	d->w = 0;
	d->f = 0;
	d->c = 0;
}

bool	check_the_diractions(char **l_map, t_mlx **mlx)
{
	t_dir d;

	init_dir(&d);
	int  i = 0;

	while (l_map[i])
	{
		if (diractions_f_c(l_map[i][0]))
		{
			if ((l_map[i][0] == 'S' && l_map[i][1] == ' ')
				|| (l_map[i][0] == 'S' && l_map[i][1] == 'O'))
				d.s++;
			else if ((l_map[i][0] == 'N' && l_map[i][1] == ' ')
				|| (l_map[i][0] == 'N' && l_map[i][1] == 'O'))
				d.n++;
			else if ((l_map[i][0] == 'W' && l_map[i][1] == ' ')
				|| (l_map[i][0] == 'W' && l_map[i][1] == 'E'))
				d.w++;
			else if ((l_map[i][0] == 'E' && l_map[i][1] == ' ')
				|| (l_map[i][0] == 'E' && l_map[i][1] == 'A'))
				d.e++;
			else if (l_map[i][0] == 'F')
			{
				(*mlx)->floor_color = handle_rgb(l_map[i], l_map);
				if (!(*mlx)->floor_color)
					return (false);
				d.f++;
			}
			else if (l_map[i][0] == 'C')
			{
				(*mlx)->sky_color =  handle_rgb(l_map[i], l_map);
				if (!(*mlx)->sky_color)
					return (false);
				d.c++;
			}
		}
		else
			break;
		i++;
	}
	if (d.e != 1 || d.n != 1 || d.s != 1 || d.w != 1 || d.c != 1 || d.f != 1)
		return(false);
	return (true);
}

void	check_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			ft_error("Error\n :)  invalid map", NULL, NULL);
		if (!characters(line[i]))
		{
			free(line);
			ft_error("Error\n :)  invalid character(s)", NULL, NULL);
		}
		i++;
	}
}