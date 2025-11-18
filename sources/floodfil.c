/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:15:57 by david             #+#    #+#             */
/*   Updated: 2025/11/18 18:54:40 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	floodfil(t_game *game, int x, int y)
{
	if (game->map.cpygrid[x][y] == '1' || game->map.cpygrid[x][y] == 'V')
		return (1);
	else if (game->map.cpygrid[x][y] == 'C')
	{
		game->infomap.collectible_found++;
		game->map.cpygrid[x][y] = 'V';
	}
	else if (game->map.cpygrid[x][y] == 'E')
	{
		game->infomap.exit_found++;
		game->map.cpygrid[x][y] = 'V';
	}
	else if (game->map.cpygrid[x][y] == 'O')
		game->map.cpygrid[x][y] = 'V';
	floodfil(game, x + 1, y);
	floodfil(game, x - 1, y);
	floodfil(game, x, y + 1);
	floodfil(game, x, y - 1);
	if (game->infomap.collectible_found == game->infomap.collectible_total
		&& game->infomap.exit_found == game->infomap.exit)
		return (0);
	return (1);
}

int	ft_cpygrid(t_game *game, int countline)
{
	int	y;

	y = 0;
	game->map.cpygrid = malloc((countline + 1) * sizeof(char *));
	if (!game->map.cpygrid)
		return (1);
	while (y < countline)
	{
		printf("[%s] len=%u\n", game->map.grid[y], (int)ft_strlen(game->map.grid[y]));
		game->map.cpygrid[y] = ft_strdup(game->map.grid[y]);
		if (!game->map.cpygrid[y])
			return ((ft_free(game, y), 1));
		y++;
	}
	game->map.cpygrid[y] = NULL;
	return (0);
}

int	ft_strlen_v2(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
