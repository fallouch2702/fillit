/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:44:57 by fallouch          #+#    #+#             */
/*   Updated: 2018/11/13 20:49:24 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char*)s;
	while (n)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
