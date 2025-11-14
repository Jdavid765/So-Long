/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:53:06 by david             #+#    #+#             */
/*   Updated: 2025/11/14 15:53:34 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check(t_game *game, int countline)
{
	// int		x;
	// int		y;

	// x = 0;
	// y = 0;
	if (check_rectangle(game, countline) == 1)
		return (1);
	// while (game->map[x][y])
	return (0);
}

int	add_map(int countline, int fd, t_game *game)
{
	int		position;

	position = 0;
	game->map.grid = malloc((countline + 1) * sizeof(char *));
	if (!game->map.grid)
		return (free(game), 1);
	game->map.grid[countline] = NULL;
	while (position < countline)
	{
		game->map.grid[position] = get_next_line(fd);
		if (!game->map.grid[position])
			return (ft_free(game, &position), 1);
		position++;
	}
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
		return (-1);
	close(fd);
	fd = open(game->map.filename, O_RDONLY);
	if (fd < 0)
		return (1);
	if (add_map(countline, fd, game) == 1)
		return (1);
	close(fd);
	return (ft_check(game, countline));
}

int	main(int ac, char **av)
{
	int		count;
	t_game	game;

	if (ac == 2)
	{
		game.map.filename = av[1];
		count = read_map(&game);
	}
	else
		return (1);
	printf("%d\n", count);
	return (0);
}