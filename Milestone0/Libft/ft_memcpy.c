/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 19:58:12 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:56:02 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destiny;
	unsigned char		*source;

	if (dest == NULL && src == NULL)
		return (NULL);
	destiny = (unsigned char *)dest;
	source = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		destiny[i] = source[i];
		i++;
	}
	return (dest);
}
/*
# include <stdio.h>

int	main(void)
{
	char	src[6] = "Hello";
	char	dst[6];

	printf("src: %s\n", src);
	printf("dst: %s\n", (char *)ft_memcpy(dst, src, 6));
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_memcpy
