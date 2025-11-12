/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:26:29 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/16 17:27:17 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_countwords(char const *s, char c)
{
	size_t	countword;
	size_t	start;
	size_t	count;

	start = 0;
	countword = 0;
	count = 0;
	while (s[start])
	{
		if (s[start] != c)
		{
			start++;
			count++;
		}
		else
		{
			start++;
			count = 0;
		}
		if (count == 1)
			countword++;
	}
	return (countword);
}

static	size_t	ft_lenword(char const *s, char c, unsigned int *start)
{
	size_t	count;

	count = 0;
	while (s[*start] && s[*start] == c)
		(*start)++;
	while (s[*start] && s[*start] != c)
	{
		count++;
		(*start)++;
	}
	return (count);
}

static	void	freemem(char **table, int i)
{
	while (i--)
		free(table[i]);
	free(table);
}

static	char	**loopwords(char **table, size_t countwords,
	char const *s, char c)
{
	unsigned int	position;
	size_t			len;
	size_t			i;

	position = 0;
	i = 0;
	while (i < countwords)
	{
		len = ft_lenword(s, c, &position);
		table[i] = ft_substr(s, position - (unsigned int)len, len);
		if (!table[i])
		{
			freemem(table, i);
			return (NULL);
		}
		i++;
	}
	table[i] = NULL;
	return (table);
}

char	**ft_split(char const *s, char c)
{
	char			**table;
	size_t			countwords;

	if (!s)
		return (NULL);
	countwords = ft_countwords(s, c);
	table = ft_calloc(countwords + 1, sizeof(char *));
	if (!table)
		return (NULL);
	if (loopwords(table, countwords, s, c) == NULL)
		return (NULL);
	return (table);
}
/*int main(void)
{
	char const s[] = "     ,salut,les, ,meilleurs, david";
	char c = ',';
	char **result = ft_split(s, c);
	for (int i = 0; result[i]; i++)
		printf("%s\n", result[i]);
	for (int i = 0; result[i]; i++)
		free(result[i]);
}*/