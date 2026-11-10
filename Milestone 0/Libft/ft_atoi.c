/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 23:11:17 by majesus           #+#    #+#             */
/*   Updated: 2026/11/10 18:32:41 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
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
			sinal *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <='9')
	{
		resultado = (resultado * 10) + (nptr[i] - '0');
		i++;
	}
	return resultado * sinal;

}

// int	main(void)
// {
// 	printf("%d\n", ft_atoi("9223372036854775809"));
//     printf("%d\n",    atoi("9223372036854775809"));
// 	return (0);
// }
