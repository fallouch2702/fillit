/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:56:25 by fallouch          #+#    #+#             */
/*   Updated: 2018/11/15 19:41:10 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *data, size_t data_size)
{
	t_list	*elem;
	void	*tmp;
	size_t	tmp_size;

	if (!(elem = malloc(sizeof(t_list))))
		return (0);
	if (data != NULL)
	{
		if (!(tmp = malloc(sizeof(void*) * data_size)))
			return (0);
		ft_memcpy(tmp, data, data_size);
		tmp_size = data_size;
		elem->content = tmp;
		elem->content_size = tmp_size;
	}
	else
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	elem->next = NULL;
	return (elem);
}
