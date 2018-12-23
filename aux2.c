/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:12:34 by fallouch          #+#    #+#             */
/*   Updated: 2018/12/03 18:52:33 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**new_tab(int i, int j)
{
	char	**tab;
	int		size;

	size = 0;
	if (!(tab = malloc(sizeof(char*) * i)))
		return (NULL);
	while (size < i)
		if (!(tab[size++] = malloc(sizeof(char) * j)))
			return (NULL);
	return (tab);
}

char	**str_to_tab(char *str)
{
	char	**tab;
	int		i;
	int		j;

	if (!(tab = new_tab(4, 6)))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
			tab[i][j++] = *str++;
		tab[i++][5] = '\0';
	}
	return (tab);
}

char	*tab_to_str(char **tab)
{
	char	*str;
	int		i;
	int		j;
	int		index;

	i = 0;
	index = 0;
	if (!(str = ft_strnew(17)))
		return (NULL);
	while (i < 4)
	{
		j = 0;
		while (tab[i][j] && tab[i][j] != '\n')
		{
			str[index++] = tab[i][j++];
		}
		while (j < 4)
		{
			str[index++] = '.';
			j++;
		}
		i++;
	}
	return (str);
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		tab[i] -= 5 - ft_strlen(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_list(t_etris **begin)
{
	t_etris		*tmp;

	while (*begin)
	{
		tmp = (*begin)->next;
		free((*begin)->content);
		free(*begin);
		*begin = tmp;
	}
}
