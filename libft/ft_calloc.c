/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:43:02 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/14 14:33:12 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*test;

	if (count == 0 || size == 0)
		return (malloc(0));
	test = malloc(count * size);
	if (!test)
		return (NULL);
	ft_bzero(test, count * size);
	return (test);
}

/*int main(void)
{
	size_t count = 5;
	int *tab = calloc(count, sizeof(int));
	for (int i = 0; i < count; i++)
		printf("%d\t", tab[i]);
}*/