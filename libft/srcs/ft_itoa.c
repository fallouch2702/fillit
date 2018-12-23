/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:43:32 by fallouch          #+#    #+#             */
/*   Updated: 2018/11/15 19:43:29 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

static char		*reverse_str(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		return (0);
	ret[i--] = 0;
	while (i >= 0)
	{
		ret[j++] = str[i--];
	}
	ret[j] = 0;
	return (ret);
}

static char		*initialize_str(int size)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(sizeof(char) * size)))
		return (0);
	while (i < size)
		str[i++] = 0;
	return (str);
}

static char		*int_min(void)
{
	char	*str;
	char	*n;
	int		i;

	i = 0;
	n = "-2147483648";
	if (!(str = malloc(sizeof(char) * 12)))
		return (0);
	while (i < 12)
	{
		str[i] = n[i];
		i++;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	char	*c;

	i = 0;
	if (!(str = initialize_str(12)))
		return (0);
	if (!(c = initialize_str(2)))
		return (0);
	if (n == 0)
		str[i++] = '0';
	if (n == -2147483648)
		return (int_min());
	c[0] = n < 0 ? '-' : c[0];
	n = n < 0 ? -n : n;
	while (n > 0)
	{
		str[i++] = '0' + n % 10;
		n = n / 10;
	}
	str[i] = 0;
	str = reverse_str(str);
	if (c[0])
		str = ft_strjoin(c, str);
	return (str);
}
