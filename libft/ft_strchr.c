/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:32:07 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/12 17:32:10 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] != (char)c)
			return (1);
		i++;
	}
	return (0);
}

/*int main(void)
{
	int test = '\0';
	char table[] = "Bonjour";
	printf("%s", ft_strchr(table, test));
}*/