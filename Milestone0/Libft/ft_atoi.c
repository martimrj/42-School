/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 23:11:17 by majesus           #+#    #+#             */
/*   Updated: 2026/11/11 16:05:17 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signal;
	long result;

	i = 0;
	signal = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			signal = signal * -1;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (int)(result * signal);
}
/*# include <stdlib.h>

int main (void)
{
	const char	*nptr = "-2147483649";
	printf("ft_atoi: %d\n", ft_atoi(nptr));
	printf("atoi: %d\n", atoi(nptr));
	return (0);
}*/
//cc -Wextra -Wall -Werror ft_atoi.c && ./a.out
