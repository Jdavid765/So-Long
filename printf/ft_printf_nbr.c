/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:49:14 by david             #+#    #+#             */
/*   Updated: 2025/10/19 18:04:02 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_printf_nbr(int n)
{
	char	tmp;
	int		count;

	count = ft_count(n);
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	if (n == -2147483648)
		write(1, "2147483648", 10);
	if (n > 9)
	{
		ft_printf_nbr(n / 10);
		ft_printf_nbr(n % 10);
	}
	if (n >= 0 && n <= 9)
	{
		tmp = n + '0';
		write(1, &tmp, 1);
	}
	return (count);
}

/*#include <stdio.h>
int	main(void)
{
	int n = 400;
	int count;
	count = ft_printf_nbr(n);
	printf("\nfaux printf resultat = %d\n", count);
	printf("vrai resultat de printf le nombre %d", n);
}*/