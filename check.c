/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:47:13 by fallouch          #+#    #+#             */
/*   Updated: 2018/12/03 19:06:35 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_link(char *piece, int i)
{
	int		count;

	count = 0;
	if (i > 0 && piece[i - 1] == '#')
		count++;
	if (i < 20 && piece[i + 1] == '#')
		count++;
	if (i <= 15 && piece[i + 5] == '#')
		count++;
	if (i >= 5 && piece[i - 5] == '#')
		count++;
	return (count);
}

int			check_link(t_etris *begin)
{
	int		i;
	int		link[2];

	while (begin)
	{
		i = 0;
		link[0] = 0;
		while ((begin->content)[i])
		{
			link[1] = 0;
			if ((begin->content)[i] == '#')
			{
				link[1] += count_link(begin->content, i);
				if (link[1] == 0)
					return (0);
				link[0] += link[1];
			}
			i++;
		}
		if (link[0] < 6)
			return (0);
		begin = begin->next;
	}
	return (1);
}

int			check_line(t_etris *begin)
{
	int		c;
	char	*tmp;

	while (begin)
	{
		c = 0;
		tmp = begin->content;
		while (*tmp)
		{
			if (*tmp == '\n')
			{
				if (c != 4)
					return (0);
				else
					c = 0;
			}
			else if (*tmp == '.' || *tmp == '#')
				c++;
			else
				return (0);
			tmp++;
		}
		begin = begin->next;
	}
	return (1);
}

int			check_count(t_etris *begin)
{
	int		tab[4];

	while (begin)
	{
		tab[0] = 0;
		tab[1] = 0;
		tab[2] = 0;
		tab[3] = 0;
		while ((begin->content)[tab[3]])
		{
			if ((begin->content)[tab[3]] == '\n')
				tab[0]++;
			else if ((begin->content)[tab[3]] == '#')
				tab[1]++;
			else if ((begin->content)[tab[3]] == '.')
				tab[2]++;
			else
				return (0);
			tab[3]++;
		}
		if (tab[0] != 4 || tab[1] != 4 || tab[2] != 12)
			return (0);
		begin = begin->next;
	}
	return (1);
}

t_etris		*check(char *file)
{
	t_etris		*begin;

	if (!(begin = read_file(file)))
		return (NULL);
	if (!(check_count(begin)))
		return (NULL);
	if (!(check_line(begin)))
		return (NULL);
	if (!(check_link(begin)))
		return (NULL);
	if (lstlen(begin) > 26)
		return (NULL);
	shaping(begin);
	return (begin);
}
