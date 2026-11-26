/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:02:39 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:56:40 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size && dst[i])
		i++;
	if (i == size)
		return (size + ft_strlen(src));
	j = 0;
	while (src[j] && (i + j) < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
int	main(void)
{
	char	dst[30] = "Ola, ";
	size_t	result;

	result = ft_strlcat(dst, "mundo!", sizeof(dst));
	ft_putstr_fd(dst, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Comprimento tentado: ", 1);
	ft_putnbr_fd((int)result, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_strlcat
