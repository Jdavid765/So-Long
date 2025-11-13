/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:59:52 by david             #+#    #+#             */
/*   Updated: 2025/11/13 15:45:02 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(int fd)
{
	int		count;
	char	*value;

	count = 0;
	while (1)
	{
		value = get_next_line(fd);
		if (value == NULL)
			break ;
		free(value);
		count++;
	}
	return (count);
}

void	ft_free(t_game **game, int *position)
{
	while ((*position--) > 0)
		free((*game)->map[*position]);
	free((*game)->map);
	free((*game));
	*game = NULL;
}

int	check_rectangle(t_game **game, int countline)
{
	t_game	*check;
	int		i;
	int		size_first_line;

	check = *game;
	size_first_line = (int)ft_strlen(check->map[0]);
	i = 0;
	while (i <= countline - 1)
	{
		if (size_first_line != (int)ft_strlen(check->map[i]))
			return (1);
		i++;
	}
	return (0);
}
