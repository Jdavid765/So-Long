/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:26:09 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/13 20:27:11 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	counts1;
	size_t	counts2;
	size_t	total;
	char	*cpy;

	counts1 = ft_strlen(s1);
	counts2 = ft_strlen(s2);
	total = counts1 + counts2 + 1;
	cpy = malloc(total * sizeof(char));
	if (!cpy)
		return (NULL);
	ft_memcpy(cpy, s1, counts1 + 1);
	ft_strlcat(cpy, s2, total);
	return (cpy);
}

/*int main(void)
{
	char const s1[] = "Bienvenue ";
	char const s2[] = "chez lego";
	char *result = ft_strjoin(s1, s2);
	printf("%s", result);
	free(result);
}*/