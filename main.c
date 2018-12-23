/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:13:08 by fallouch          #+#    #+#             */
/*   Updated: 2018/12/03 19:09:52 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		error(int n)
{
	if (n == 1)
		ft_putendl("error");
	if (n == 2)
		ft_putendl("usage: ./fillit source_file");
	return (0);
}

int		print_map(char *map, int size, t_etris *begin)
{
	int		i;

	i = 0;
	while (map[i])
	{
		ft_putchar(map[i++]);
		if (i % size == 0)
			ft_putchar('\n');
	}
	free_list(&begin);
	free(map);
	exit(1);
	return (1);
}

int		main(int ac, char **av)
{
	char		*map;
	t_etris		*begin;
	int			sqrt;

	if (ac != 2)
		return (error(2));
	if (!(begin = check(av[1])))
		return (error(1));
	sqrt = ft_sqrt(begin);
	map = new_map(sqrt);
	while (solve(map, sqrt, begin, 'A') == 2)
	{
		free(map);
		map = new_map(++sqrt);
	}
	free_list(&begin);
}
