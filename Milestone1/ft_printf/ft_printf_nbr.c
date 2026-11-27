/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 20:39:24 by majesus           #+#    #+#             */
/*   Updated: 2026/11/27 20:42:36 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_nbr(int nbr)
{
	long	n;
	int		count;
	int		written;

	n = nbr;
	count = 0;
	if (n < 0)
	{
		if (ft_printf_char('-') < 0)
			return (-1);
		count = 1;
		n = -n;
	}
	written = ft_printf_base((unsigned long)n, "0123456789");
	if (written < 0)
		return (-1);
	count += written;
	return (count);
}
