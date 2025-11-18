/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:25:06 by david             #+#    #+#             */
/*   Updated: 2025/11/18 12:47:53 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int	tmp_x;
	int	tmp_y;
	
	tmp_x = 0;
	tmp_y = 0;
	if (keycode == game->player.UP)
		return (tmp_x--, ft_move_player(game, tmp_x, tmp_y),game->player.walk++, 0);
	else if (keycode == game->player.LEFT)
		return (tmp_y--, ft_move_player(game, tmp_x, tmp_y),game->player.walk++, 0);
	else if (keycode == game->player.DOWN)
		return (tmp_x++, ft_move_player(game, tmp_x, tmp_y),game->player.walk++, 0);
	else if (keycode == game->player.RIGHT)
		return (tmp_y++, ft_move_player(game, tmp_x, tmp_y),game->player.walk++, 0);	
	else if (keycode == game->player.ESC)
		ft_exit(game);
	return (1);
}

void	ft_move_player(t_game *game, int tmp_x, int tmp_y)
{
	tmp_x = tmp_x + game->player.x;
	tmp_y = tmp_y + game->player.y;
	if (game->map.grid[tmp_x][tmp_y] == '1')
		return ;
	else if (game->map.grid[tmp_x][tmp_y] == 'C')
	{
		game->infomap.collectible_found++;
		game->map.grid[game->player.x][game->player.y] = 'O';
		game->map.grid[tmp_x][tmp_y] = 'P';
		game->player.x = tmp_x;
		game->player.y = tmp_y;
		draw_map(game);
		return ;
	}
	else if (game->map.grid[tmp_x][tmp_y] == 'E')
	{
		if (game->infomap.collectible_found == game->infomap.collectible_total)
		{
			ft_printf("Bien jouer tu as fini le jeux !");
			ft_exit(game);
		}
		ft_printf("Tu n'as pas tout les collectibles");
		return ;
	}
	else if (game->map.grid[tmp_x][tmp_y] == 'O')
	{
		game->map.grid[game->player.x][game->player.y] = 'O';
		game->map.grid[tmp_x][tmp_y] = 'P';
		game->player.x = tmp_x;
		game->player.y = tmp_y;
		draw_map(game);
		return ;
	}
}

// void	follow_move_player(t_game *game, int tmp_x , int tmp_y)
// {
	
// }