/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:58:42 by david             #+#    #+#             */
/*   Updated: 2025/10/20 14:13:15 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_printhexa(unsigned long long int adresse, char tmp, int *count)
{
	if (adresse >= 16)
	{
		ft_printhexa(adresse / 16, tmp, count);
		ft_printhexa(adresse % 16, tmp, count);
	}
	if (adresse < 16 && tmp == 'x')
		*count += ft_printf_char(HEX_LOW[adresse]);
	return (*count);
}

int	ft_printf_ptr(void *content)
{
	int						count;
	unsigned long long int	adresse;

	count = 0;
	if (!content)
		return (write(1, "(nil)", 5));
	adresse = (unsigned long long int)content;
	count += ft_printf_str("0x");
	ft_printhexa(adresse, 'x', &count);
	return (count);
}

// int	main(void)
// {
// 	int a = 16;
// 	int count = 0;
// 	char tmp = 'x';
// 	int total = printf("vrai : %p\n", (void *)&a);
// 	int total2 = ft_printf_ptr((void *)&a);
// 	printf("\n");
// 	printf("%d\n", total);
// 	printf("%d\n", total2);
// }