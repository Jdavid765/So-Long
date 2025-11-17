/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:57:53 by david             #+#    #+#             */
/*   Updated: 2025/11/17 23:24:43 by david            ###   ########.fr       */
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

int	ft_key_hook(int keycode, t_game *game)
{
	if (ft_check_keycode(keycode, game) == 0)
	{
		ft_printf("Movements player = %d\n", game->player.walk);
	}
	else
		ft_printf("You can't move with this touche\n");
	return (0);
}
int	ft_check_keycode(int keycode, t_game *game)
{
	if (keycode == game->player.UP)
		return (game->player.walk++, 0);
	else if (keycode == game->player.LEFT)
		return (game->player.walk++, 0);
	else if (keycode == game->player.DOWN)
		return (game->player.walk++, 0);
	else if (keycode == game->player.RIGHT)
		return (game->player.walk++, 0);	
	else if (keycode == game->player.ESC)
		ft_exit(game);
	return (1);
}

void	ft_exit(t_game *game)
{
	mlx_loop_end(game->mlx.minlibx);
	mlx_destroy_window(game->mlx.minlibx, game->mlx.win);
	mlx_destroy_display(game->mlx.minlibx);
	free(game->mlx.minlibx);
}

// void	ft_move_player(t_game *game)
// {
// 	if (game->map.grid[game->player.x][game->player.y] == '1')
// 	{
// 		game->player.x--;
// 		return ;
// 	}
// 	game->map.grid[game->player.x][game->player.y] = 'P';
// }