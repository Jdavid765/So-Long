/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:57:53 by david             #+#    #+#             */
/*   Updated: 2025/11/17 19:52:57 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
	game->mlx.minlibx = mlx_init();
	start_image(game);
	game->mlx.win = mlx_new_window(game->mlx.minlibx, game->mlx.width, game->mlx.height, "DBZ");
	draw_map(game);
	mlx_key_hook(game->mlx.win, ft_print_walk, game);
	mlx_loop(game->mlx.minlibx);
}

int	ft_print_walk(int keycode, t_game *game)
{
	ft_printf("Numbers of movements = %d\tavec la touche = %d\n", game->player.walk, keycode);
	game->player.walk++;
	return (0);
}
int	ft_check_keycode(int keycode, t_game *game)
{
	
}
