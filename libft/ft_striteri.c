/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:46:51 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/12 19:46:56 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		(*f)(i++, s);
		s++;
	}
}
/*void mafonction(unsigned int index, char *string)
{
	*string = *string + index;
}
int main(void)
{
	char s[] = "abc";
	void (*f)(unsigned int, char *);
	f = &mafonction;
	ft_striteri(s, f);
}*/