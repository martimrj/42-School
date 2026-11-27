/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:46:26 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:55:41 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] = "ab\0cd";

	printf("1) %d\n", ft_memchr(s, 'c', 5) == memchr(s, 'c', 5));
	printf("2) %d\n", ft_memchr(s, 'c', 3) == memchr(s, 'c', 3));
	printf("3) %d\n", ft_memchr(s, 'a', 0) == memchr(s, 'a', 0));
	printf("4) %d\n", ft_memchr(s, 'a' + 256, 5) == memchr(s, 'a' + 256, 5));
	printf("5) %d\n", ft_memchr(s, '\0', 5) == memchr(s, '\0', 5));
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_memchr
