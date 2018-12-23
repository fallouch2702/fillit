/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:37:55 by fallouch          #+#    #+#             */
/*   Updated: 2018/11/15 19:40:42 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_lstlen(t_list *begin)
{
	int	i;

	i = 0;
	if (!begin)
		return (0);
	while (begin)
	{
		i++;
		begin = begin->next;
	}
	return (i);
}
