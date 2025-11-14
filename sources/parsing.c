/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:59:52 by david             #+#    #+#             */
/*   Updated: 2025/11/14 15:52:52 by david            ###   ########.fr       */
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

void	ft_free(t_game *game, int *position)
{
	while ((*position--) > 0)
		free(game->map.grid[*position]);
	free(game->map.grid);
}

int	check_rectangle(t_game *game, int countline)
{
	int		i;
	int		size_first_line;

	size_first_line = (int)ft_strlen(game->map.grid[0]);
	i = 0;
	while (i <= countline - 1)
	{
		if (size_first_line != (int)ft_strlen(game->map.grid[i]))
			return (1);
		i++;
	}
	if (check_rectangle2(game, countline) == 1)
		return (1);
	return (0);
	
}
int	check_rectangle2(t_game *game, int countline)
{
	int	i;

	i = 0;
	while (i <= countline - 1)
	{
		if (i == 0 || i == (countline - 1))
		{
			if (ft_strchr(game->map.grid[i], '1') == 1)
				return (1);
			i++;
		}
		else
		{
			if (check_side_rec(game, i) == 1)
				return (1);
			i++;
		}
	}
	return (0);
}

int	check_side_rec(t_game *game, int i)
{
	int		size;
	int		x;

	x = 0;
	size = ft_strlen(game->map.grid[i]);
	if (game->map.grid[i][x] != '1' || game->map.grid[i][size - 1] != '1')
		return (1);
	x++;
	return (0);
}