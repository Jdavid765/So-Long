/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:58:49 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/20 13:58:02 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_selectf(char tmp, va_list current)
{
	int	count;

	count = 0;
	if (tmp == 's')
		count += ft_printf_str(va_arg(current, char *));
	else if (tmp == 'c')
		count += ft_printf_char(va_arg(current, int));
	else if (tmp == 'd' || tmp == 'i')
		count += ft_printf_nbr(va_arg(current, int));
	else if (tmp == 'u')
		count += ft_printf_dec(va_arg(current, unsigned int));
	else if (tmp == '%')
		count += ft_printf_char('%');
	else if (tmp == 'x' || tmp == 'X')
		ft_printf_hexa(va_arg(current, unsigned int), tmp, &count);
	else if (tmp == 'p')
		count += ft_printf_ptr(va_arg(current, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	current;

	count = 0;
	va_start (current, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_selectf(*format, current);
		}
		else
			count += ft_printf_char(*format);
		format++;
	}
	va_end (current);
	return (count);
}

// #include <stdio.h>
// int main(void) 
// {
// 	//int d = 2332;
//     //const char s[] = "bonjour paul";
// 	//const char c = 'A';
// 	//unsigned int u = 0;
// 	//int total = ft_printf("Résultat = %s\n", s);
// 	//int total2 = printf("Résultat = %s\n", s);
// 	//ft_printf("%d", total);
// 	//printf("\n%d",total2);
// 	//char sign = '%';
// 	//int total = ft_printf("%%", sign);
// 	//ft_printf("%d",total);
// 	//unsigned int x = -100;
// 	//int i = 42;
// 	unsigned long long int pointeur = 2;
// 	int total = ft_printf("faux printf result = %p\n", (void *)&pointeur);
// 	int total2 = printf("vrai printf result = %p\n", (void *)&pointeur);
// 	ft_printf("faux printf = %d\n", total);
// 	printf("vrai printf = %d\n", total2);
// 	return (0);
// }
