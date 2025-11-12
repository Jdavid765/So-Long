/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:39:52 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/14 13:09:55 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*fake;

	fake = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		fake[i] = (unsigned char)c;
		i++;
	}
	return (fake);
}

/*int main(void)
{
	char table[] = "ABCD ZEFE";
	int test = 'A';
	int size = 3;
	printf("%s", (char *)ft_memset(table, test, size));
	return (0);
}*/