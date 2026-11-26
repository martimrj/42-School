/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 16:25:29 by majesus           #+#    #+#             */
/*   Updated: 2026/11/26 16:29:23 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int written;

	if(!s)
	{
		written = write(1, "(null)", 6);
		if (written < 0)
			return (-1);
		return (write);
	}
	writen = write( 1, s, ft_strlen(s));
	if (written < 0)
		return (-1);
	return (written)
}
