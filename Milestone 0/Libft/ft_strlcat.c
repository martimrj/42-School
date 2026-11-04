/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-29 17:02:39 by majesus           #+#    #+#             */
/*   Updated: 2026-10-29 17:02:39 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t length_dst;
	size_t	i;

	i = 0;
	length_dst = ft_strlen(dst);
	if(length_dst >= size)
		return (size + ft_strlen(src));
	while(src[i] && length_dst + i < size - 1)
	{
		dst[length_dst + i] = src[i]; 
		i++;
	}
	dst[length_dst + i] = '\0';
	return (length_dst + ft_strlen(src));
}

// int main (void)
// {
// 	char	a[10] = "aaaaaa";
// 	char	b[10] = "bbbb";
// 	size_t		i;

// 	printf("Dst: %s\n", a);
// 	i = ft_strlcat(a, b, 4);
// 	printf("Dst + src: %s\n", a);
// 	printf("Valor: %zu", i);
// 	return (1);
// }

