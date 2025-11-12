/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:06:43 by david             #+#    #+#             */
/*   Updated: 2025/11/12 13:03:17 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpyyy(char *line, int *position)
{
	char	*dest;
	int		total;
	char	*start;

	total = ft_strleno(line) + 1;
	start = malloc((total + 1) * sizeof(char));
	dest = start;
	while (line[*position] && line[*position] != '\n')
	{
		*dest++ = line[*position];
		(*position)++;
	}
	if (line[*position] == '\n')
	{
		*dest++ = line[*position];
		(*position)++;
	}
	*dest = '\0';
	return (start);
}

int	ft_strleno(char *s)
{
	int	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

char	*ft_strjoino(char *s1, char *s2)
{
	char	*cpy;
	int		i;
	int		total;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	total = ft_strleno(s1) + ft_strleno(s2) + 1;
	cpy = malloc(total * sizeof(char));
	if (!cpy)
		return (NULL);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	while (s2[j])
		cpy[i++] = s2[j++];
	cpy[i] = '\0';
	return (cpy);
}

int	ft_strchra(char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == '\n')
			return (1);
		x++;
	}
	return (0);
}

char	*ft_strdupo(char *s, int position)
{
	char	*cpy;
	int		size;
	int		i;

	size = ft_strleno(s) + 1;
	i = 0;
	cpy = malloc(size * sizeof(char));
	if (!cpy)
		return (NULL);
	while (s[position])
	{
		cpy[i] = s[position];
		i++;
		position++;
	}
	cpy[i] = '\0';
	return (cpy);
}

// int	main(void)
// {
// 	// char	*cpy;
// 	// char line[] = "je suis l'école 42davida\n vdaivd";
// 	// cpy = ft_strcpy(line);
// 	// printf("%s", cpy);
// }
// j'ai mis en commentaire le \n pour mon getnextline car je ne veux pas qu'il le lise pour n'avoir que les informations de la map