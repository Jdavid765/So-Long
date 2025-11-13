/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:03:57 by david             #+#    #+#             */
/*   Updated: 2025/11/13 22:47:21 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_game
{
	char			**map;
	struct s_game	*next;
}					t_game;

int		count_line(int fd);
int		read_map(void);
void	ft_free(t_game **game, int *position);
int		check_rectangle(t_game **game, int position);
int		check_side_rec(t_game **game, int i);
int		check_rectangle2(t_game **game, int countline);

#endif