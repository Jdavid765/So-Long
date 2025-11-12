/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:27:55 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/12 17:28:31 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	tmp;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n == -2147483648)
		write(fd, "2147483648", 10);
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n >= 0 && n <= 9)
	{
		tmp = n + '0';
		write(fd, &tmp, 1);
	}
}
/*int main(void)
{
	int n = -2147483648;
	int fd = 1;
	ft_putnbr_fd(n, fd);
}*/