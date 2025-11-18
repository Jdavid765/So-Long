/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:57:53 by david             #+#    #+#             */
/*   Updated: 2025/11/18 12:35:32 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
	game->mlx.minlibx = mlx_init();
	start_image(game);
	game->mlx.win = mlx_new_window(game->mlx.minlibx, game->mlx.width, game->mlx.height, "DBZ");
	draw_map(game);
	mlx_key_hook(game->mlx.win, ft_key_hook, game);
	mlx_loop(game->mlx.minlibx);
}

void	ft_exit(t_game *game)
{
	mlx_loop_end(game->mlx.minlibx);
	mlx_destroy_window(game->mlx.minlibx, game->mlx.win);
	mlx_destroy_display(game->mlx.minlibx);
	free(game->mlx.minlibx);
}
