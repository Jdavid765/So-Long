/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:21:19 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/13 19:25:08 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	size_t	size;

	size = ft_strlen(s) + 1;
	cpy = malloc(size * sizeof(char));
	if (!cpy)
		return (NULL);
	ft_memcpy(cpy, s, size);
	return (cpy);
}
/*int main(void)
{
	const char table[] = "david";
	printf("%s", ft_strdup(table));
}*/