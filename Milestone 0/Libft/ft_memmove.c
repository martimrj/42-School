/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-28 20:17:50 by majesus           #+#    #+#             */
/*   Updated: 2026-10-28 20:17:50 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destiny;
	const unsigned char	*source;

	destiny = dest;
	source = src;
	if (src > dest)
		ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			destiny[n] = source[n];
	}
	return (dest);
}

// #include "stdio.h"
// #include "string.h"

// int	main(void)
// {
// 	char	a[] = "123456789";
// 	char	b[] = "123456789";

// 	memmove(a, a + 3, 5);
// 	ft_memmove(b, b + 3, 5);
// 	printf("libc: %s\nft_memmove: %s\n", a, b);
// 	return (0);
// }
