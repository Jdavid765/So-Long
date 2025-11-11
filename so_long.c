/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:53:06 by david             #+#    #+#             */
/*   Updated: 2025/11/11 19:44:46 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int fd;
	fd = open("maps.ber", O_RDONLY);
	if (fd == -1)
		return (1);
	int count = 0;
	while (count < 30)
	{
		char *resultat = get_next_line(fd);
		if (resultat == NULL)
			break ;
		printf("%s", resultat);
		free(resultat);
		count++;





		
	}
	close(fd);
}