/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:36:58 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/12 17:38:26 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	countneedle;

	i = 0;
	countneedle = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			if (i + countneedle <= len
				&& ft_strncmp(&haystack[i], needle, countneedle) == 0)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	const char haystack[] = "j ai un sac remplie de bonbon";
	const char needle[] = "sa";
	int len = 19;
	char *result = ft_strnstr(haystack, needle, len);
	printf("%s", result);
}*/