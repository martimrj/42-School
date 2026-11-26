/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 16:30:53 by majesus           #+#    #+#             */
/*   Updated: 2026/11/26 16:35:00 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Pseudocodigo para ft_printf_u:
1. Se nbr tiver mais de um algarismo, processar recursivamente nbr / 10.
2. Converter nbr % 10 para caracter e escreve-lo no stdout.
3. Contar os caracteres escritos.
4. Devolver a contagem ou -1 se uma escrita falhar.
*/

int	ft_print_nbr(int nb)
{
	long	n;
	int		written;

	n = nb;
	if (n < 0)
	{
		n = n * -1;
		written = write(1, '-', 1);
		if (written < 0)
			return (-1);
	}
	written = ft_printf_base(n, "0123456789");
	if (written < 0)
		return (-1);
	if (nb < 0)
		return (written + 1);
	return (written);
}
