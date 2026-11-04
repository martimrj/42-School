/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-02 23:11:17 by majesus           #+#    #+#             */
/*   Updated: 2026-11-02 23:11:17 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	atoi(const char *nptr)
{
	int	i;
	int	sinal;
	int	resultado;

	i = 0;
	sinal = 1;
	resultado = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] =='-')
		{
			sinal *= -1;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <='9')
	{
		resultado = (resultado * 10) + (nptr[i] - '0');
		i++;
	}
	return resultado;

}
