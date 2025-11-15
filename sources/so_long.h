/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:03:57 by david             #+#    #+#             */
/*   Updated: 2025/11/15 11:52:14 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_map
{
	char	**grid;
	char	**cpygrid;
	char	*filename;
}			t_map;

typedef struct s_player
{
	int	x;
	int	y;
}		t_player;

typedef struct s_infomap
{
	int	player;
	int	collectible_total;
	int	cell;
	int	exit;
	int	wall;
	int	collectible_found;
	int	exit_found;
}		t_infomap;

typedef struct s_game
{
	t_map		map;
	t_infomap	infomap;
	t_player	player;
}			t_game;

int		count_line(int fd);
int		read_map(t_game *game);
void	ft_free(t_game *game, int position);
int		check_rectangle(t_game *game, int position);
int		check_side_rec(t_game *game, int i);
int		check_rectangle2(t_game *game, int countline);
int		floodfil(t_game *game, int x, int y);

#endif