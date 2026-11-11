/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 23:15:00 by majesus           #+#    #+#             */
/*   Updated: 2026/11/11 17:46:59 by majesus          ###   ########.fr       */
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

// int main(void)
// {
// 	int number = -12345;
// 	char *str = ft_itoa(number);
// 	if (str)
// 	{
// 		printf("The string representation of %d is: %s\n", number, str);
// 		free(str);
// 	}
// 	return 0;
// }
