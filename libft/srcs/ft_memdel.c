/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:23:05 by fallouch          #+#    #+#             */
/*   Updated: 2018/11/14 18:12:06 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = 0;
	}
}