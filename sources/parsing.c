/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:59:52 by david             #+#    #+#             */
/*   Updated: 2025/11/13 16:59:22 by david            ###   ########.fr       */
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
	i = 0;
	while (i <= countline - 1)
	{
		if (i == 0 || i == (countline - 1))
		{
			if (ft_strchr(check->map[i], '1') == 1)
				return (1);
		}
		else
		{
			if (check_side_rec(&check, i) == 1)
				return (1);
		}
	}
	return (0);
}

int	check_side_rec(t_game **game, int i)
{
	t_game	*side;
	int		size;

	side = *game;
	size = ft_strlen(side->map[i]);
	if (side->map[i][0] != '1' && side->map[i][size - 1] != '1')
		return (1);
	return (0);
}