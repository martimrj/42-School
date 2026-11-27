/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 20:39:32 by majesus           #+#    #+#             */
/*   Updated: 2026/11/27 20:39:33 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ptr(void *ptr)
{
	int		count;
	int		written;

	if (!ptr)
		return (ft_printf_str("(nil)"));
	written = write(1, "0x", 2);
	if (written != 2)
		return (-1);
	count = ft_printf_base((unsigned long)ptr, "0123456789abcdef");
	if (count < 0)
		return (-1);
	return (count + 2);
}
