/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 19:21:58 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:56:11 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello World";
	int 	c = 0;
	size_t	n = 5;
	printf("original :%s\n", str);
	printf("%s\n", (char *)ft_memset(str, c, n));
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_memset
