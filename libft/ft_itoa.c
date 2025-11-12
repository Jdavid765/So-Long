/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:25:09 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/16 17:25:13 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_countn(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	else if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static	void	ft_addchar(int len, char *cpy, int n)
{
	long	nb;

	nb = n;
	if (nb == 0)
		cpy[0] = '0';
	if (nb < 0)
	{
		cpy[0] = '-';
		nb *= -1;
	}
	while (nb)
	{
		cpy[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*cpy;

	len = ft_countn(n);
	cpy = malloc(len * sizeof(char) + 1);
	if (!cpy)
		return (NULL);
	cpy[len] = '\0';
	ft_addchar(len, cpy, n);
	return (cpy);
}

/*int main(void)
{
	int n = -2147483648;
	char *result = ft_itoa(n);
	printf("%s", result);
}*/