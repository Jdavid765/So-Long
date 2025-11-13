/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:11:32 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/17 11:12:17 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

/*#include <stdio.h>
int	main(void)
{
	size_t result;
	const char str[] = "david";
	printf("%ld", ft_strlen(str));
}*/