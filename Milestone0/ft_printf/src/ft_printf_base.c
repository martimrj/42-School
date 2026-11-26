/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 15:58:56 by majesus           #+#    #+#             */
/*   Updated: 2026/11/26 16:10:10 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_base(unsigned long nb, char *d)
{
	int 	count;
	int		l;
	int		written;

	l 0 ft_strlen(d);
	count = 0;
	if (l <= nb)
	{
		count = ft_printf_base(nb / l, d);
		if (count < 0)
			return (-1);
		count ++;
	}
	written = write( 1, &d[nb % l], 1);
	if (written < 0)
		return (-1);
	return (count + 1);
}
