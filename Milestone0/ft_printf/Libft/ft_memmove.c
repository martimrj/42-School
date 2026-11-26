/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 20:17:50 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:56:07 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*destiny;
	const unsigned char		*source;
	size_t					i;

	if (dest == NULL && src == NULL)
		return (NULL);
	destiny = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	i = n;
	while (i > 0)
	{
		i--;
		destiny[i] = source[i];
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	dest[20];
	const char	*src = "Hello, World!";
	size_t	n = 5;

	ft_memmove(dest, src, n);
	dest[n] = '\0';

	printf("Copied string: %s\n", dest);
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_memmove
