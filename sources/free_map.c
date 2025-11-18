/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:49:42 by david             #+#    #+#             */
/*   Updated: 2025/11/18 18:33:14 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_all_map(t_game *game, int countline)
{
	int	i;

	i = 0;
	while (i < countline)
	{
		free(game->map.grid[i]);
		free(game->map.cpygrid[i]);
		i++;
	}
	free(game->map.grid);
	free(game->map.cpygrid);
}