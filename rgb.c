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
	int i = 0;

	while (split[i])
		free(split[i++]);
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
			if (color->r < 0 || color->r > 255)
			{
				free_split(split);
				free(color);
				printf("R range\n");
				return (NULL);
			}
			color->g = ft_atoi(split[1]);
			if (color->g < 0 || color->g > 255)
			{
				free_split(split);
				free(color);
				printf("G range\n");
				return (NULL);
			}
			color->b = ft_atoi(split[2]);
			if (color->b < 0 || color->b > 255)
			{
				free_split(split);
				free(color);
				printf("B range\n");
				return (NULL);
			}
            free_split(split);
			return (color);
		}
        free_split(split);
		free(color);
	}
	return (NULL);
}