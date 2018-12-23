/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:10:54 by fallouch          #+#    #+#             */
/*   Updated: 2018/12/03 19:04:23 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			lstlen(t_etris *begin)
{
	int		i;

	i = 0;
	while (begin)
	{
		i++;
		begin = begin->next;
	}
	return (i);
}

t_etris		*new_elem(char *content)
{
	static int	n = 0;
	t_etris		*new;

	if (!(new = malloc(sizeof(t_etris))))
		return (NULL);
	if (!(new->content = ft_strnew(21)))
		return (NULL);
	new->content = ft_strcpy(new->content, content);
	new->next = NULL;
	new->n = n++;
	return (new);
}

void		lst_push(t_etris **begin, char *content)
{
	t_etris		*tmp;

	tmp = *begin;
	if (!(*begin))
		*begin = new_elem(content);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_elem(content);
	}
}

int			check_list(t_etris *begin)
{
	if (!begin)
		return (0);
	while (begin->next)
	{
		if ((begin->content)[BUFF_SIZE - 1] == '\n')
			(begin->content)[BUFF_SIZE - 1] = 0;
		else
			return (0);
		begin = begin->next;
	}
	if ((begin->content)[BUFF_SIZE - 1] == '\n')
		return (0);
	return (1);
}

t_etris		*read_file(char *file)
{
	t_etris		*begin;
	char		buf[BUFF_SIZE + 1];
	int			fd;
	int			ret;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	begin = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (ret < 0 || ret < 20)
			return (NULL);
		buf[ret] = 0;
		lst_push(&begin, buf);
		ft_strclr(buf);
	}
	close(fd);
	if (ret < 0 || !check_list(begin))
		return (NULL);
	return (begin);
}
