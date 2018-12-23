/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:27:26 by fallouch          #+#    #+#             */
/*   Updated: 2018/12/03 18:51:34 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	initialize(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

int		replace(char **str, char a, char b)
{
	int		i;

	if (!(*str))
		return (0);
	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == a)
			(*str)[i] = b;
		i++;
	}
	return (0);
}

char	*push_up(char *str)
{
	char	*ret;
	int		j;

	j = 0;
	ret = ft_strnew(21);
	while (!(ft_strncmp(str, "....\n", 5)))
		str += 5;
	ret = ft_strcat(ret, str);
	while (ft_strlen(ret) != 20)
		ret = ft_strcat(ret, "....\n");
	return (ret);
}

char	*push_left(char *str)
{
	char	**tab;
	char	*ret;
	int		i;

	if (!(tab = str_to_tab(str)))
		return (NULL);
	while (tab[0][0] == '.' && tab[1][0] == '.' && tab[2][0] == '.')
	{
		i = 0;
		while (i < 4)
			tab[i++]++;
	}
	if (!(ret = tab_to_str(tab)))
		return (NULL);
	free_tab(tab);
	free(str);
	return (ret);
}

void	shaping(t_etris *begin)
{
	char	*tmp;

	while (begin)
	{
		tmp = push_left(push_up(begin->content));
		free(begin->content);
		begin->content = ft_strdup(tmp);
		free(tmp);
		begin = begin->next;
	}
}
