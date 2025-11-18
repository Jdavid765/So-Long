/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:33:42 by david             #+#    #+#             */
/*   Updated: 2025/11/18 19:26:42 by david            ###   ########.fr       */
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
	game->data.height = 0;
	game->data.width = 0;
	game->data.image = NULL;
	game->mlx.width = 1600;
	game->mlx.height = 1200;
	game->data.scale_x = 0;
	game->data.scale_y = 0;
	game->player.walk = 0;
	game->player.down = 115;
	game->player.left = 113;
	game->player.right = 100;
	game->player.up = 122;
	game->player.esc = 65307;
	game->mlx.size_line = 0;
	game->data.x_exit = 0;
	game->data.y_exit = 0;
}
