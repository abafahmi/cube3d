#include "cub3d.h"

int	aaf_strnstr(char *big, char *little)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(big);
	if ((!big && !*little) || len == 5)
		return (0);
	i = 0;
	while (big[i])
	{
		j = 0;
		while (little[j] == big[i + j])
		{
			j++;
			if (little[j] == '\0' && big[i + j] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int	free_all(char **str_array)
{
	int	i;

	i = 0;
	if (str_array)
	{
		while (str_array[i] != NULL)
		{
			free(str_array[i]);
			i++;
		}
		free(str_array);
		return (0);
	}
	return (0);
}

void	ft_error1(char *msg, char *line)
{
	ft_putstr_fd(msg, 2);
	free(line);
	exit(1);
}

void	ft_error(char *msg, char **str, char **s2)
{
	ft_putstr_fd(msg, 2);
	free_all(str);
	free_all(s2);
	exit(1);
}