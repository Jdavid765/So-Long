/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:53:06 by david             #+#    #+#             */
/*   Updated: 2025/11/13 15:44:08 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check(t_game **game, int countline)
{
	t_game	*check;

	check = *game;
	if (check_rectangle(&check, countline) == 1)
		return (1);
	return (0);
}

t_game	*add_map(int countline, int fd)
{
	int		position;
	t_game	*game;

	position = 0;
	game = malloc(sizeof(*game));
	if (!game)
		return (NULL);
	game->next = NULL;
	game->map = malloc((countline + 1) * sizeof(char *));
	if (!game->map)
		return (free(game), NULL);
	game->map[countline] = NULL;
	while (position < countline)
	{
		game->map[position] = get_next_line(fd);
		if (!game->map[position])
			return (ft_free(&game, &position), NULL);
		position++;
	}
	return (game);
}

int	read_map(void)
{
	int		fd;
	int		countline;
	t_game	*game;
	int		check;

	countline = 0;
	fd = open("sources/maps.ber", O_RDONLY);
	if (fd < 0)
		return (1);
	countline = count_line(fd);
	if (countline <= 0)
		return (-1);
	close(fd);
	fd = open("sources/maps.ber", O_RDONLY);
	if (fd < 0)
		return (1);
	game = NULL;
	game = add_map(countline, fd);
	if (game->map == NULL)
		return (1);
	close(fd);
	check = ft_check(&game, countline);
	return (check);
}

int	main(void)
{
	int count = read_map();
	printf("%d\n", count);
}