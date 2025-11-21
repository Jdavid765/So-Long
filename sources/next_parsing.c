/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:09:49 by david             #+#    #+#             */
/*   Updated: 2025/11/21 13:29:23 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collecte_infomap(t_game *game, int x, int y)
{
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
		{
			game->data.x_exit = x;
			game->data.y_exit = y;
			game->infomap.exit++;
		}
		else if (game->map.grid[x][y] == '0')
			game->infomap.cell++;
		else if (game->map.grid[x][y] == '1')
			game->infomap.wall++;
		else
			return (1);
		y++;
	}
	return (0);
}
