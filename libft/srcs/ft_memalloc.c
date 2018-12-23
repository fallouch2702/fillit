/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:12:31 by fallouch          #+#    #+#             */
/*   Updated: 2018/11/12 15:21:04 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t				i;
	void				*ptr;
	char				*tmp;

	i = 0;
	if (!(ptr = malloc(sizeof(void*) * size)))
		return (0);
	tmp = (char*)ptr;
	while (i <= size)
	{
		tmp[i] = 0;
		i++;
	}
	return (ptr);
}
