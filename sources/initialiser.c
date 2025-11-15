/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:33:42 by david             #+#    #+#             */
/*   Updated: 2025/11/15 20:54:57 by david            ###   ########.fr       */
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
	game->mlx.screen = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.screen, 1920, 1080, "pacman");
	mlx_loop(game->mlx.screen);
}