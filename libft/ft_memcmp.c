/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:24:59 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/12 17:25:02 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*real_s1;
	const unsigned char	*real_s2;

	i = 0;
	real_s1 = (const unsigned char *)s1;
	real_s2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (!(real_s1[i] == real_s2[i]))
			return (real_s1[i] - real_s2[i]);
		i++;
	}
	return (0);
}
/*int main(void)
{
	const char s1[] = "dav";
	const char s2[] = "davia";
	int n = 4;
	printf("%d", ft_memcmp(s1, s2, n));
}*/