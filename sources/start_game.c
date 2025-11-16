/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:57:53 by david             #+#    #+#             */
/*   Updated: 2025/11/16 17:48:46 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
	game->mlx.minlibx = mlx_init();
	// start_image(game);
	game->mlx.win = mlx_new_window(game->mlx.minlibx, 1920, 1080, "DBZ");
	start_image(game);
	mlx_loop(game->mlx.minlibx);
}

void	start_image(t_game *game)
{
	int	x = 0;
	int	y = 0;

	game->data.image = mlx_new_image(game->mlx.minlibx, 64, 64);
	game->data.addr = mlx_get_data_addr(game->data.image, &game->data.bits_pixel, &game->data.line, &game->data.endian);
	while (x < 100)
	{
		y = 0;
		while (y < 50)
		{
			my_mlx_pixel_put(game, x, y, 0x00FF0000);
			mlx_put_image_to_window(game->mlx.minlibx, game->mlx.win, game->data.image, x, y);
			y++;
		}
		x++;
	}
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->data.addr + (y * game->data.line + x * (game->data.bits_pixel/ 8));
	*(unsigned int*)dst = color;
}

// void	*texture(t_game *game)
// {
	
// }