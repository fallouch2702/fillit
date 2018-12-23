/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnret.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:02:03 by fallouch          #+#    #+#             */
/*   Updated: 2018/11/15 19:41:22 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstnret(t_list *begin, size_t n)
{
	if (!begin)
		return (NULL);
	while (begin && n)
	{
		begin = begin->next;
		n--;
	}
	if (begin)
		return (begin);
	return (0);
}
