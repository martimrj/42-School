/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 17:56:36 by majesus           #+#    #+#             */
/*   Updated: 2026/11/27 21:48:46 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_printf_char(va_arg(*ap, int)));
	if (c == 's')
		return (ft_printf_str(va_arg(*ap, char *)));
	if (c == 'p')
		return (ft_printf_ptr(va_arg(*ap, void *)));
	if (c == 'd' || c == 'i')
		return (ft_printf_nbr(va_arg(*ap, int)));
	if (c == 'u')
		return (ft_printf_base(va_arg(*ap, unsigned int), "0123456789"));
	if (c == 'x')
		return (ft_printf_base(va_arg(*ap, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_printf_base(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_printf_char('%'));
	return (-1);
}

static int	writer(const char *format, size_t *i, va_list *va)
{
	int	written;

	if (format[*i] != '%')
	{
		written = ft_printf_char(format[*i]);
		if (written < 0)
			return (-1);
	}
	else
	{
		written = check(format[*i + 1], va);
		if (written < 0)
			return (-1);
		(*i)++;
	}
	(*i)++;
	return (written);
}

int	ft_printf(const char *fmt, ...)
{
	size_t	i;
	int		total;
	int		written;
	va_list	var;

	i = 0;
	total = 0;
	va_start(var, fmt);
	while (fmt[i])
	{
		written = writer(fmt, &i, &var);
		if (written < 0)
			return (-1);
		total += written;
	}
	va_end(var);
	return (total);
}
