/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:33:42 by david             #+#    #+#             */
/*   Updated: 2025/11/17 14:45:51 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_game *game)
{
	game->infomap.player = 0;
	game->infomap.collectible_total = 0;
	game->infomap.cell = 0;
	game->infomap.exit = 0;
	game->infomap.wall = 0;
	game->infomap.collectible_found = 0;
	game->infomap.exit_found = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.deplacement = 0;
	game->data.height = 64;
	game->data.width = 64;
	game->data.image = NULL;
	game->mlx.width = 1920;
	game->mlx.height = 1080;
}
