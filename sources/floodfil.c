/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:15:57 by david             #+#    #+#             */
/*   Updated: 2025/11/17 16:58:42 by david            ###   ########.fr       */
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
	game->map.cpygrid = malloc((countline) * sizeof(char *));
	if (!game->map.cpygrid)
		free(game->map.cpygrid);
	game->map.cpygrid[countline] = NULL; 
	while (y < countline)
	{
		game->map.cpygrid[y] = ft_strdup(game->map.grid[y]);
		if (!game->map.cpygrid)
			return ((free(game->map.cpygrid), 1));
		y++;
	}
	return (0);
}
