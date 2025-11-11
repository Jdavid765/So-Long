/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:06:11 by david             #+#    #+#             */
/*   Updated: 2025/11/05 07:02:45 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer, char *line)
{
	int			nb_bytes;
	char		*tmp;

	nb_bytes = 1;
	if (fd < 0 || !buffer || !line)
		return (NULL);
	while (nb_bytes > 0 && ft_strchr(line) == 0)
	{
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nb_bytes == -1)
			return (free(line), NULL);
		buffer[nb_bytes] = '\0';
		tmp = ft_strjoin(line, buffer);
		if (!tmp)
			return (free(line), NULL);
		free(line);
		line = tmp;
	}
	return (line);
}

char	*ft_extract(char *line, int *position)
{
	char	*stake;

	if (line && line[*position] != '\0')
	{
		stake = ft_strdup(line, *position);
		free(line);
		*position = 0;
		return (stake);
	}
	else
	{
		free(line);
		*position = 0;
		return (NULL);
	}
}

char	*ft_next_get_line(int fd, char **line, char *buffer)
{
	static int	position;
	char		*cpy;

	if (!(*line))
	{
		*line = malloc(1);
		if (!(*line))
			return (NULL);
		(*line)[0] = '\0';
		position = 0;
	}
	*line = ft_read(fd, buffer, *line);
	free(buffer);
	if (*line == NULL)
		return (free(*line), NULL);
	if ((*line)[0] == '\0')
		return (free(*line), *line = NULL, NULL);
	cpy = ft_strcpy(*line, &position);
	if (!cpy)
		return (free(*line), *line = NULL, NULL);
	*line = ft_extract(*line, &position);
	return (cpy);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	char		*cpy;

	cpy = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	cpy = ft_next_get_line(fd, &line, buffer);
	if (!cpy)
		return (free(line), line = NULL, NULL);
	return (cpy);
}

// int	main(void)
// {
// 	int	fd;
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (-1);
// 	int count = 0;
// 	while (count < 10)
// 	{
// 		char *result = get_next_line(fd);
// 		printf("%s", result);
// 		free (result);
// 		count++;
// 	}
// 	close(fd);
// 	return (0);
// }