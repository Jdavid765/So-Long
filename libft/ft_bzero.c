/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:17:46 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/12 17:17:59 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*fake;

	i = 0;
	fake = (unsigned char *)s;
	while (i < n)
	{
		fake[i] = 0;
		i++;
	}
}

/*int main(void)
{
	char table[] = "David zdzd";
	int size = 10;
	ft_bzero(table, size);
	return (0);
}*/