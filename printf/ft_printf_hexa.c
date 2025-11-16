/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:11:56 by david             #+#    #+#             */
/*   Updated: 2025/10/20 14:13:09 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexa(unsigned int n, char tmp, int *count)
{
	if (n >= 16)
	{
		ft_printf_hexa(n / 16, tmp, count);
		ft_printf_hexa(n % 16, tmp, count);
	}
	if (n < 16 && tmp == 'x')
		*count += ft_printf_char(HEX_LOW[n]);
	else if (n < 16 && tmp == 'X')
		*count += ft_printf_char(HEX_UPP[n]);
	return (*count);
}

// #include <stdio.h>
// int	main(void)
// {
// 	unsigned int x = 42;
// 	char s[] = "0123456789abcdef";
// 	//unsigned int s = 568041472;
// 	int total = printf("%x", x);
// 	int count = 0;
// 	int total2 = printf("\n%d", ft_printf_hexa(x, 'x', &count));
// 	printf("%d", total);
// 	//printf("%d\n", total);
// 	//printf("%08X\n", s);
// 	//int total2 = printf("%x\n", ft_printf_hexa(x,s));
// }