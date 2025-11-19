/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abafahmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:21:25 by abafahmi          #+#    #+#             */
/*   Updated: 2024/11/27 17:16:30 by abafahmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_free_strjoin(char *buffer, char *temp_buf)
{
	char	*holder;

	holder = ft_strjoin(buffer, temp_buf);
	free(buffer);
	return (holder);
}

char	*the_line(char **buffer)
{
	char	*line;
	char	*newline;
	char	*temp;
	size_t	line_len;

	newline = ft_strchr(*buffer, '\n');
	if (!newline)
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
		return (line);
	}
	line_len = newline - *buffer + 1;
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *buffer, line_len + 1);
	temp = ft_strdup(newline + 1);
	free(*buffer);
	*buffer = temp;
	return (line);
}

char	*ft_get(int fd, char *buffer)
{
	char	*temp_buf;
	ssize_t	bytes_read;

	temp_buf = malloc(BUFFER_SIZE + 1);
	if (!temp_buf)
		return (NULL);
	while (!buffer || !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp_buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp_buf);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		temp_buf[bytes_read] = '\0';
		buffer = ft_free_strjoin(buffer, temp_buf);
	}
	free(temp_buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_get(fd, buffer);
	if (!buffer || buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (the_line(&buffer));
}
/*
int main()
{
    int fd = open("text.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
    	printf("%s", line);
	free(line);
    }
    close(fd);
}*/
