/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:53:06 by david             #+#    #+#             */
/*   Updated: 2025/11/18 19:35:43 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_size_line(t_game *game)
{
	int	x;

	x = 0;
	while (game->map.grid[1][x] && game->map.grid[1][x] != '\n')
	{
		game->mlx.size_line++;
		x++;
	}
}

int	ft_check(t_game *game, int countline)
{
	if (check_rectangle(game, countline) == 1)
		return (1);
	if (game->infomap.cell < 0)
		return (1);
	else if (game->infomap.collectible_total < 0)
		return (1);
	else if (game->infomap.exit != 1)
		return (1);
	else if (game->infomap.player != 1)
		return (1);
	if (ft_cpygrid(game, countline) == 1)
		return (1);
	if (floodfil(game, game->player.x, game->player.y) == 1)
		return (1);
	game->infomap.collectible_found = 0;
	return (0);
}

int	add_map(int countline, int fd, t_game *game)
{
	int		position;

	position = 0;
	game->map.grid = malloc((countline + 1) * sizeof(char *));
	if (!game->map.grid)
		return (free(game), 1);
	
	while (position < countline)
	{
		game->map.grid[position] = get_next_line(fd);
		if (!game->map.grid[position])
			return (ft_free(game, position), 1);
		position++;
	}
	game->map.grid[position] = NULL;
	return (0);
}

int	read_map(t_game *game)
{
	int		fd;
	int		countline;

	countline = 0;
	fd = open(game->map.filename, O_RDONLY);
	if (fd < 0)
		return (1);
	countline = count_line(fd);
	if (countline <= 0)
		return (1);
	close(fd);
	fd = open(game->map.filename, O_RDONLY);
	if (fd < 0)
		return (1);
	if (add_map(countline, fd, game) == 1)
		return (ft_free_all_map(game,countline), 1);
	close(fd);
	if (ft_check(game, countline) == 1)
		return (ft_printf("Erreur de map incorrecte"),ft_free_all_map(game,countline), 1);
	take_size_line(game);
	if (start_game(game, countline) == 1)
		return (ft_free_all_map(game,countline), 1);
	ft_free_all_map(game, countline);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		init(&game);
		game.map.filename = av[1];
		read_map(&game);
	}
	else
		return (1);
	return (0);
}