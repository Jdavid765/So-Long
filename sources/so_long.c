/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:53:06 by david             #+#    #+#             */
/*   Updated: 2025/11/12 15:50:56 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fd()

int	ft_parsage(char *map)
{
	printf("%s", map);
	return (0);
}

int	main(void)
{
	int fd;
	fd = open("sources/maps.ber", O_RDONLY);
	if (fd == -1)
		return (1);
	int count = 0;
	char *resultat = get_next_line(fd);
	while(count < 9)
	{
	resultat = ft_strjoin(resultat, get_next_line(fd));
	count++;
	}
	printf("%s", resultat);
	// int parsage = 
	close(fd);
}
// #include <stdio.h>
// #include <fcntl.h>
// #include "../gnl/get_next_line.h"

// int	main(void)
// {
// 	int fd = open("maps.ber", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Erreur d'ouverture bro");
// 		return (1);
// 	}

// 	printf("Fichier ouvert ✅\n");

// 	char *resultat = get_next_line(fd);

// 	if (!resultat)
// 		printf("get_next_line a retourné NULL ❌\n");
// 	else
// 		printf("Ligne lue : %s\n", resultat);

// 	close(fd);
// 	return (0);
// }
