/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:57:53 by david             #+#    #+#             */
/*   Updated: 2025/11/16 23:00:07 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
	game->mlx.minlibx = mlx_init();
	start_image(game);
	game->mlx.win = mlx_new_window(game->mlx.minlibx, 1920, 1080, "DBZ");
	draw_map(game);
	mlx_loop(game->mlx.minlibx);
}

void	start_image(t_game *game)
{
	game->data.player = mlx_xpm_file_to_image(game->mlx.minlibx, "images/vegeto.xpm", &game->data.width, &game->data.height);
	game->data.wall = mlx_xpm_file_to_image(game->mlx.minlibx, "images/wall.xpm", &game->data.width, &game->data.height);
	game->data.floor = mlx_xpm_file_to_image(game->mlx.minlibx, "images/floor.xpm", &game->data.width, &game->data.height);
	game->data.coin = mlx_xpm_file_to_image(game->mlx.minlibx, "images/coin.xpm", &game->data.width, &game->data.height);
	game->data.exit = mlx_xpm_file_to_image(game->mlx.minlibx, "images/exit.xpm", &game->data.width, &game->data.height);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.grid[x])
	{
		y = 0;
		while (game->map.grid[x][y] && game->map.grid[x][y] != '\n')
		{
			game->data.image = choose_pixel(game, x, y);
			if (game->data.image)
				mlx_put_image_to_window(game->mlx.minlibx, game->mlx.win, game->data.image, game->data.width * y, game->data.width * x);
			y++;
		}
		x++;
	}
}

void	*choose_pixel(t_game *game, int x, int y)
{
	if (game->map.grid[x][y] == '1')
		return (game->data.wall);
	else if (game->map.grid[x][y] == 'O')
		return (game->data.floor);
	else if (game->map.grid[x][y] == 'P')
		return (game->data.player);
	else if (game->map.grid[x][y] == 'E')
		return (game->data.exit);
	else if (game->map.grid[x][y] == 'C')
		return (game->data.coin);

	return (NULL);
}