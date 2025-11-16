/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:18:59 by david             #+#    #+#             */
/*   Updated: 2025/10/19 18:04:14 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ftcount(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_printf_dec(unsigned int n)
{
	char	tmp;
	int		count;

	count = ftcount(n);
	if (n > 9)
	{
		ft_printf_dec(n / 10);
		ft_printf_dec(n % 10);
	}
	if (n <= 9)
	{
		tmp = n + '0';
		write(1, &tmp, 1);
	}
	return (count);
}

/*#include <stdio.h>
int	main(void)
{
	unsigned int u = -2147483648;
	printf("%u", u);
	//int count = ft_printf_dec(u);
	//printf("\n%d\n", count);
}*/