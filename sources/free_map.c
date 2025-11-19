/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:49:42 by david             #+#    #+#             */
/*   Updated: 2025/11/19 18:53:12 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_all_map(t_game *game, int countline)
{
	int	i;

	i = 0;
	while (i < countline)
	{
		if (game->map.grid)
			free(game->map.grid[i]);
		if (game->map.cpygrid)
			free(game->map.cpygrid[i]);
		i++;
	}
	free(game->map.grid);
	free(game->map.cpygrid);
}
