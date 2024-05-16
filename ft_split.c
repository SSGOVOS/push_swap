/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:16:20 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/09 16:04:43 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	numberofwords(char *s, char c)
{
	size_t	i;
	size_t	wordscounter;

	i = 0;
	wordscounter = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			wordscounter++;
		i++;
	}
	return (wordscounter);
}

static void	funfree(char **p, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words && p[i])
	{
		free(p[i]);
		p[i] = NULL;
		i++;
	}
	free(p);
	p = NULL;
}

static void	at3mr(char **dest, char *s, char c, size_t words)
{
	size_t	lenw;
	size_t	i;
	size_t	j;
	size_t	start;

	lenw = 0;
	i = 0;
	j = 0;
	while (j < words && s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if ((i == 0 || s[i - 1] == c) && s[i] != '\0')
			start = i;
		while (s[i] != c && s[i] != '\0')
		{
			lenw++;
			i++;
		}
		dest[j] = ft_substr(s, start, lenw);
		if (dest[j] == NULL)
			funfree(dest, words);
		lenw = 0;
		j++;
	}
}

char	**ft_split(char *s, char c)
{
	char	**p;
	size_t	words;

	if (!s)
		return (NULL);
	words = numberofwords(s, c);
	p = ft_calloc(words + 1, sizeof(char **));
	if (!p)
		return (NULL);
	at3mr(p, s, c, words);
	return (p);
}

void	fnfree(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
