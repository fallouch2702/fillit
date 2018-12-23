/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:50:29 by fallouch          #+#    #+#             */
/*   Updated: 2018/11/15 19:43:31 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_list_push_front(t_list **begin_list, void const *data,
		size_t data_size)
{
	t_list	*elem;

	elem = ft_lstnew(data, data_size);
	elem->next = *begin_list;
	*begin_list = elem;
}
