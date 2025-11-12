/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:54:58 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/13 16:00:24 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*real_s;

	i = 0;
	real_s = (const unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (real_s[i] == (unsigned char)c)
			return ((unsigned char *)&real_s[i]);
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	const char table[] = "Bonjour";
	int test = 'j';
	int n = 0;
	printf("%s", (unsigned char *)ft_memchr(table, test, n));
}*/