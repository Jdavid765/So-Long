/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:34:54 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/14 14:37:01 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t				i;
	unsigned char		*real_dest;
	const unsigned char	*real_src;

	real_dest = (unsigned char *)dest;
	real_src = (const unsigned char *)src;
	i = 0;
	if (real_dest == NULL && real_src == NULL)
		return (real_dest);
	if (real_dest > real_src)
	{
		while (size-- > 0)
			(real_dest[i + size]) = (real_src[i + size]);
	}
	else
	{
		while (size > 0)
		{
			real_dest[i] = real_src[i];
			i++;
			size--;
		}
	}
	return (real_dest);
}

/*int main(void)
{
	int size = 5;
	char dest[] = "SALUT TOUT LE MONDE";
	char src[] = "salut tt tout le monde";
	printf("%s\n", (char *)ft_memmove(dest + 2, dest, size));
	return (0);
}*/
