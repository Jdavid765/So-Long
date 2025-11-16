/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:57:53 by david             #+#    #+#             */
/*   Updated: 2025/11/16 13:39:08 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
	game->mlx.screen = mlx_init();
	start_image(game);
	game->mlx.win = mlx_new_window(game->mlx.screen, 1920, 1080, "fortnite");
	mlx_loop(game->mlx.screen);
}

void	start_image(t_game *game)
{
		game->data.image = mlx_new_image(game->mlx.screen, 1920, 1080);
	game->data.addr = mlx_get_data_addr("../images/vegeto.xmp",
			&game->data.bits_pixel, &game->data.line, &game->data.endian);
}