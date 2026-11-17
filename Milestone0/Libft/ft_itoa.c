/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 23:15:00 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 15:35:20 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long n)
{
	int	count;

	count = 1;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*str;

	nb = n;
	if (nb < 0)
		nb = -nb;
	len = count_digits(nb);
	if (n < 0)
		len++;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
/*
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	int		tests[] = {0, 7, -7, 10, 100, -123, INT_MAX, INT_MIN};
	char	*s;
	size_t	i;

	i = 0;
	while (i < sizeof(tests) / sizeof(tests[0]))
	{
		s = ft_itoa(tests[i]);
		printf("%d -> [%s]\n", tests[i], s);
		free(s);
		i++;
	}
	return (0);
}*/
//cc -Wextra -Wall -Werror ft_itoa.c && ./a.out
//2147483648
