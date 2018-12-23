/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:37:38 by fallouch          #+#    #+#             */
/*   Updated: 2018/12/03 18:52:17 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(t_etris *begin)
{
	int		i;
	int		n;

	i = 2;
	n = 0;
	while (begin)
	{
		n++;
		begin = begin->next;
	}
	n = n * 4;
	while (i * i < n)
		i++;
	return (i);
}

int		verif_map(char *map, int size, char *piece, char x)
{
	int		i;
	int		j;
	int		c;

	initialize(&c, &i, &j);
	while (map[j] != x)
		j++;
	map = map + ((j / size) * size);
	while (piece[i])
	{
		if (piece[i++] == '#')
			c++;
		if (i % 4 == 0 && i)
		{
			j = 0;
			while (j < size && c && map[j])
				if (map[j++] == x)
					c--;
			if (!c)
				map += size;
			else
				return (0);
		}
	}
	return (1);
}

char	*new_map(int size)
{
	char	*map;
	int		i;

	i = 0;
	if (!(map = ft_strnew(size * size + 1)))
		return (NULL);
	while (i < size * size)
		map[i++] = '.';
	return (map);
}

int		place(int size, char **map, t_etris *begin, int index)
{
	int		i;
	int		c;
	int		add;
	char	*piece;

	i = 0;
	c = 0;
	piece = begin->content;
	while (piece[i] && c < 4)
	{
		add = (size - 4) * (i / 4);
		if (piece[i] == '#')
		{
			if (index + i + add < size * size && (*map)[index + i + add] == '.')
			{
				(*map)[index + i + add] = 'A' + (begin->n);
				c++;
			}
		}
		i++;
	}
	if (c < 4 || !verif_map(*map, size, piece, 'A' + (begin->n)))
		return (replace(&(*map), 'A' + (begin->n), '.'));
	return (1);
}

int		solve(char *map, int size, t_etris *begin, char x)
{
	static t_etris	*tmp = 0;
	int				index;

	if (!(tmp))
		tmp = begin;
	index = 0;
	if (!begin)
		return (print_map(map, size, tmp));
	while (index < (size * size))
	{
		if (place(size, &map, begin, index))
			solve(map, size, begin->next, x + 1);
		else
			index++;
	}
	if (index == size * size)
		return (2);
	return (1);
}
