#include "cub3d.h"

int	split_contain(char **split)
{
	int i = 0;
	while (split[i])
		i++;
	if (i == 3)
		return (1);
	return (0);
}

void free_split(char **split)
{
    free(split[0]);
    free(split[1]);
    free(split[2]);
    free(split);
}

t_rgb	*handle_rgb(char *str, char **l_map)
{
	t_rgb *color;
	int i = 0;
	
	color = ft_calloc(sizeof(t_rgb), 1);
	if (!color)
		ft_error("calloc failed", l_map, NULL);	
	while (str[i] && (str[i] < '0' || str[i] > '9'))
		i++;
	if (str[i])
	{
		char **split;
		split = ft_split(str + i, ',');
		if (split_contain(split))
		{
			color->r = ft_atoi(split[0]);
			color->g = ft_atoi(split[1]);
			color->b = ft_atoi(split[2]);
            free_split(split);
			return (color);
		}
		return (NULL);
	}
	ft_error("RGB !!", l_map, NULL);
	return (NULL);
}