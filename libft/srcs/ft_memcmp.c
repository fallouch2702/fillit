/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:50:57 by fallouch          #+#    #+#             */
/*   Updated: 2018/11/14 16:11:41 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	i = 0;
	while (i < n && ptr1[i] == ptr2[i])
		i++;
	if (!s1 || !s2 || !n)
		return (0);
	if (i == n)
		return (ptr1[i - 1] - ptr2[i - 1]);
	return (ptr1[i] - ptr2[i]);
}
