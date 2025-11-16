/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:15:57 by david             #+#    #+#             */
/*   Updated: 2025/11/16 12:52:02 by david            ###   ########.fr       */
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
