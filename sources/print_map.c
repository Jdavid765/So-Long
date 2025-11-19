/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:07:25 by david             #+#    #+#             */
/*   Updated: 2025/11/19 15:57:49 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_image(t_game *game)
{
	game->data.player = mlx_xpm_file_to_image(game->mlx.minlibx,
			"textures/alessio.xpm", &game->data.width, &game->data.height);
	game->data.wall = mlx_xpm_file_to_image(game->mlx.minlibx,
			"textures/42.xpm", &game->data.width, &game->data.height);
	game->data.floor = mlx_xpm_file_to_image(game->mlx.minlibx,
			"textures/floor.xpm", &game->data.width, &game->data.height);
	game->data.coin = mlx_xpm_file_to_image(game->mlx.minlibx,
			"textures/dia.xpm", &game->data.width, &game->data.height);
	game->data.exit = mlx_xpm_file_to_image(game->mlx.minlibx,
			"textures/daniel.xpm", &game->data.width, &game->data.height);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x] && game->map.grid[y][x] != '\n')
		{
			game->data.image = choose_pixel(game, x, y);
			if (game->data.image)
				mlx_put_image_to_window(game->mlx.minlibx, game->mlx.win,
					game->data.image, game->data.width * x,
					game->data.height * y);
			x++;
		}
		y++;
	}
}

void	*choose_pixel(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == '1')
		return (game->data.wall);
	else if (game->map.grid[y][x] == 'O')
		return (game->data.floor);
	else if (game->map.grid[y][x] == 'P')
		return (game->data.player);
	else if (game->map.grid[y][x] == 'E')
		return (game->data.exit);
	else if (game->map.grid[y][x] == 'C')
		return (game->data.coin);
	return (NULL);
}
