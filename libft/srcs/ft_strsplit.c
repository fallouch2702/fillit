/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:24:28 by fallouch          #+#    #+#             */
/*   Updated: 2018/11/14 17:31:43 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		count_words(char const *s, char c)
{
	int		count_words;

	count_words = 0;
	while (*s)
	{
		if ((*s != c && *(s - 1) == c) || (*s != c && *(s - 1) == '\0'))
		{
			count_words++;
		}
		s++;
	}
	return (count_words);
}

static int		*size_words(char const *s, char c)
{
	int		*size_words;
	int		i;
	int		words;
	int		index;

	words = count_words(s, c);
	if (!(size_words = malloc(sizeof(int) * words)))
		return (0);
	i = 0;
	while (i < words)
	{
		size_words[i] = 0;
		i++;
	}
	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
			size_words[index]++;
		else if (i > 0 && s[i - 1] != c)
			index++;
		i++;
	}
	return (size_words);
}

static void		ft_initialize(int *i, int *j, int *index)
{
	*index = 0;
	*j = 0;
	*i = -1;
}

char			**ft_strsplit(char const *s, char c)
{
	char		**new;
	int			i;
	int			index;
	int			j;

	if (!s || !(new = (char**)malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (NULL);
	ft_initialize(&i, &j, &index);
	while (s[++i])
	{
		if (s[i] != c)
		{
			if (i == 0 || (s[i] != c && s[i - 1] == c))
				new[index] = malloc(size_words(s, c)[index] * sizeof(char));
			new[index][j++] = s[i];
		}
		else if (i > 0 && s[i - 1] != c)
		{
			new[index++][j] = 0;
			j = 0;
		}
	}
	new[count_words(s, c)] = 0;
	return (new);
}
