/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:57:53 by david             #+#    #+#             */
/*   Updated: 2025/11/21 13:28:23 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	start_game(t_game *game, int countline)
{
	game->map.grid[game->data.x_exit][game->data.y_exit] = '0';
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
	mlx_hook(game->mlx.win, 2, 1L << 0, ft_key_hook, game);
	mlx_hook(game->mlx.win, 17, 0, ft_close_mouse, game);
	mlx_loop(game->mlx.minlibx);
	ft_exit(game);
	return (0);
}

void	ft_exit(t_game *game)
{
	ft_free_image(game);
	mlx_destroy_window(game->mlx.minlibx, game->mlx.win);
	mlx_destroy_display(game->mlx.minlibx);
	free(game->mlx.minlibx);
}

void	ft_free_image(t_game *game)
{
	mlx_destroy_image(game->mlx.minlibx, game->data.floor);
	mlx_destroy_image(game->mlx.minlibx, game->data.exit);
	mlx_destroy_image(game->mlx.minlibx, game->data.coin);
	mlx_destroy_image(game->mlx.minlibx, game->data.wall);
	mlx_destroy_image(game->mlx.minlibx, game->data.player);
}

int	ft_close_mouse(t_game *game)
{
	ft_printf("You close the windows with the mouse\n");
	mlx_loop_end(game->mlx.minlibx);
	return (0);
}
