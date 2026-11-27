/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 20:39:20 by majesus           #+#    #+#             */
/*   Updated: 2026/11/27 20:39:21 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	string_length(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_printf_base(unsigned long nb, const char *digits)
{
	size_t	base;
	int		count;
	int		written;

	base = string_length(digits);
	if (base < 2)
		return (-1);
	count = 0;
	if (nb >= base)
	{
		count = ft_printf_base(nb / base, digits);
		if (count < 0)
			return (-1);
	}
	written = write(1, &digits[nb % base], 1);
	if (written != 1)
		return (-1);
	return (count + 1);
}
