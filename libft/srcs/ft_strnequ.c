/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 21:04:30 by fallouch          #+#    #+#             */
/*   Updated: 2018/11/14 17:17:59 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (*s1 == *s2 && *s1 && i < n)
	{
		i++;
		s1++;
		s2++;
	}
	if (!n)
		return (1);
	if (i == n)
		return (1);
	if (*s1 == *s2)
		return (1);
	else
		return (0);
}
