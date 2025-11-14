/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:59:52 by david             #+#    #+#             */
/*   Updated: 2025/11/14 22:53:02 by david            ###   ########.fr       */
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

int	check_side_rec(t_game *game, int x)
{
	int		size;
	int		y;

	y = 0;
	size = ft_strlen(game->map.grid[x]);
	if (game->map.grid[x][y] != '1' || game->map.grid[x][size - 1] != '1')
		return (1);
	y++;
	while (game->map.grid[x][y] && game->map.grid[x][y] != '\n')
	{
		if (game->map.grid[x][y] == 'P')
		{
			game->player.x = x;
			game->player.y = y;
			game->infomap.player++;
		}
		else if (game->map.grid[x][y] == 'C')
			game->infomap.collectible_total++;
		else if (game->map.grid[x][y] == 'E')
			game->infomap.exit++;
		else if (game->map.grid[x][y] == 'O')
			game->infomap.cell++;
		else if (game->map.grid[x][y] == '1')
			game->infomap.wall++;
		else
			return (1);
		y++;
	}
	return (0);
}

int	floodfil(t_game *game, int x, int y)
{
	if (game->map.cpygrid[x][y] == 1 || game->map.cpygrid[x][y] == 'v')
		return ;
	if (game->infomap.collectible_found == game->infomap.collectible_total
		&& game->infomap.exit_found == game->infomap.exit)
		return (0);
}
