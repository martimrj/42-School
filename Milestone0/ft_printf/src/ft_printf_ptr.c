/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 16:36:30 by majesus           #+#    #+#             */
/*   Updated: 2026/11/26 16:40:40 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Pseudocodigo para ft_printf_ptr:
1. Converter o endereco para um inteiro sem sinal suficientemente grande.
2. Escrever o prefixo "0x".
3. Se o endereco for NULL, escrever '0'; caso contrario, escrever os digitos
   do endereco em hexadecimal minusculo, do mais significativo ao menos.
4. Devolver o total de caracteres escritos ou -1 se houver erro.
*/

int	ft_printf_ptr(void *ptr)
{
	int				written;
	unsigned long	n;

	if (!s)
	{
		written = write(1, "(nill)", 6);
		if (written < 0)
			return (-1);
		return (written);
	}
	n = (unsigned long) ptr;
	written = write(1, "0x", 2);
	if(var < 0)
		return (-1);
	written = ft_printf_base(n, "01234567890abcdef");
	if(written < 0)
		return (-1);
	return (written + 2);
}
