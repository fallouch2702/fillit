/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:26:12 by fallouch          #+#    #+#             */
/*   Updated: 2018/11/10 20:43:01 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char*)dest;
	ptr2 = (unsigned char*)src;
	while (n)
	{
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
		n--;
		if (*(ptr1 - 1) == (unsigned char)c)
			return (ptr1);
	}
	return (0);
}
