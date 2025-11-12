/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 23:05:45 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/13 23:05:55 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*cpy;
	unsigned int	i;
	size_t			len;

	i = 0;
	len = ft_strlen(s);
	cpy = malloc(len * sizeof(char) + 1);
	if (!cpy)
		return (NULL);
	cpy[len] = '\0';
	while (i < len)
	{
		cpy[i] = (*f)(i, s[i]);
		i++;
	}
	return (cpy);
}
/*char mafonction(unsigned int index, char string)
{
	char tmp;

	tmp = string + index;
	return (tmp);
}
int main(void)
{
	char const s[] = "abc";
	char (*f)(unsigned int, char);
	f = &mafonction;
	char *result = ft_strmapi(s, f);
	printf("%s", result);
}*/