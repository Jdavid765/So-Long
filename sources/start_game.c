/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:57:53 by david             #+#    #+#             */
/*   Updated: 2025/11/18 19:42:20 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	start_game(t_game *game, int countline)
{
	game->map.grid[game->data.x_exit][game->data.y_exit] = 'O';
	game->mlx.minlibx = mlx_init();
	if (!game->mlx.minlibx)
		return (free(game->mlx.minlibx), 1);
	start_image(game);
	game->mlx.win = mlx_new_window(game->mlx.minlibx,
			game->data.width * game->mlx.size_line,
			game->data.height * countline, "DBZ");
	if (!game->mlx.win)
		return (free(game->mlx.minlibx), 1);
	draw_map(game);
	mlx_key_hook(game->mlx.win, ft_key_hook, game);
	mlx_loop(game->mlx.minlibx);
	ft_exit(game);
	return (0);
}

void	ft_exit(t_game *game)
{
	free(game->data.player);
	free(game->data.floor);
	free(game->data.coin);
	free(game->data.wall);
	free(game->data.exit);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.minlibx, game->mlx.win);
	if (game->mlx.minlibx)
	{
		mlx_destroy_display(game->mlx.minlibx);
		free(game->mlx.minlibx);
	}
}
