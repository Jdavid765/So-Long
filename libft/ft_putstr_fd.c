/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:28:39 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/12 17:28:42 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *c, int fd)
{
	while (*c)
	{
		write(fd, c, 1);
		c++;
	}
}
/*int main(void)
{
	char s[] = "Bonjour je suis le livreur";
	int fd = 1;
	ft_putstr_fd(s, fd);
}*/