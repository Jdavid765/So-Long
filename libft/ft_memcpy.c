/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:11:58 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/14 13:37:12 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destination;
	const unsigned char	*source;

	i = 0;
	destination = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (destination == NULL && source == NULL)
		return (destination);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (destination);
}
/*int main(int argc, char **argv)
{
	int size = 3;
	if (argc > 1)
		printf("%s\n", (char *)ft_memcpy(argv[1] + 2, argv[1], size));
	return (0);
}*/
