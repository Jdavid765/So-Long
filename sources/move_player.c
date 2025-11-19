/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:25:06 by david             #+#    #+#             */
/*   Updated: 2025/11/19 18:54:54 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_game *game)
{
	int	result;

	result = ft_check_keycode(keycode, game);
	if (result == 0)
		ft_printf("Movements player = %d\n", game->player.walk);
	else if (result == 2)
	{
		ft_printf("Good Job you finish the game 2D!\n");
		mlx_loop_end(game->mlx.minlibx);
		return (1);
	}
	else if (result == 5)
	{
		ft_printf("You leave the game !\n");
		mlx_loop_end(game->mlx.minlibx);
		return (1);
	}
	return (0);
}

int	ft_check_keycode(int keycode, t_game *game)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = 0;
	tmp_y = 0;
	if (keycode == game->player.up)
		return (tmp_x--, ft_move_player(game, tmp_x, tmp_y));
	else if (keycode == game->player.left)
		return (tmp_y--, ft_move_player(game, tmp_x, tmp_y));
	else if (keycode == game->player.down)
		return (tmp_x++, ft_move_player(game, tmp_x, tmp_y));
	else if (keycode == game->player.right)
		return (tmp_y++, ft_move_player(game, tmp_x, tmp_y));
	else if (keycode == game->player.esc)
	{
		mlx_loop_end(game->mlx.minlibx);
		return (5);
	}
	return (1);
}

int	ft_move_player(t_game *game, int tmp_x, int tmp_y)
{
	tmp_x = tmp_x + game->player.x;
	tmp_y = tmp_y + game->player.y;
	if (game->map.grid[tmp_x][tmp_y] == '1')
		return (1);
	else if (game->map.grid[tmp_x][tmp_y] == 'C')
	{
		if (follow_move_player(game, tmp_x, tmp_y) == 0)
			return (0);
	}
	else if (game->map.grid[tmp_x][tmp_y] == 'E')
	{
		if (game->infomap.collectible_found == game->infomap.collectible_total)
			return (2);
		ft_printf("You can't take the door\n");
		return (1);
	}
	else if (game->map.grid[tmp_x][tmp_y] == 'O')
	{
		if (follow_move_player(game, tmp_x, tmp_y) == 0)
			return (0);
	}
	return (1);
}

int	follow_move_player(t_game *game, int tmp_x, int tmp_y)
{
	if (game->map.grid[tmp_x][tmp_y] == 'C')
	{
		game->infomap.collectible_found++;
		game->map.grid[game->player.x][game->player.y] = 'O';
		game->map.grid[tmp_x][tmp_y] = 'P';
		game->player.x = tmp_x;
		game->player.y = tmp_y;
		game->player.walk++;
		if (game->infomap.collectible_found == game->infomap.collectible_total)
			ft_put_door(game);
		draw_map(game);
		return (0);
	}
	else if (game->map.grid[tmp_x][tmp_y] == 'O')
	{
		game->map.grid[game->player.x][game->player.y] = 'O';
		game->map.grid[tmp_x][tmp_y] = 'P';
		game->player.x = tmp_x;
		game->player.y = tmp_y;
		game->player.walk++;
		draw_map(game);
		return (0);
	}
	return (1);
}

void	ft_put_door(t_game *game)
{
	game->map.grid[game->data.x_exit][game->data.y_exit] = 'E';
	draw_map(game);
}
