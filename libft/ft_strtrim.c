/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:38:58 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/12 17:39:01 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*cpy;

	if (!s1)
		return (ft_calloc(1, 1));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	len = end - start;
	cpy = ft_substr(s1, start, len);
	return (cpy);
}

/*int main(void)
{
	char const s1[] = "    \n David\t le stud\t   ";
	char const set[] = " \n\t";
	char *result = ft_strtrim(s1, set);
	printf("[%s]", result);
	free(result);
}*/