/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:26:10 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/13 20:22:09 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	counts;
	char	*cpy;

	if (!len || (start > ft_strlen(s)))
	{
		cpy = malloc(1);
		if (!cpy)
			return (NULL);
		cpy[0] = '\0';
		return (cpy);
	}
	else if (ft_strlen(&s[start]) < len)
		counts = ft_strlen(&s[start]);
	else
		counts = len;
	cpy = malloc(counts * sizeof(char) + 1);
	if (!cpy)
		return (NULL);
	ft_memcpy(cpy, &s[start], counts);
	cpy[counts] = '\0';
	return (cpy);
}
/*int main(void)
{
	char const s[] = "";
	unsigned int start = 1;
	size_t len = 1;
	char *result = ft_substr(s, start, len);
	printf("%s", result);
	free(result);
}*/