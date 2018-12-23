/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:10:14 by fallouch          #+#    #+#             */
/*   Updated: 2018/11/13 21:15:59 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	size_t	i;
	int		pos;
	int		len;

	i = 0;
	pos = 0;
	len = 0;
	while (s2[len] != '\0')
		len++;
	if (len == 0)
		return ((char *)s1);
	while (s1[i] && i < size)
	{
		while (s2[pos] == s1[i + pos] && (i + pos) <= size)
		{
			if (pos == len - 1)
				return ((char*)(s1 + i));
			pos++;
		}
		pos = 0;
		i++;
	}
	return (0);
}
