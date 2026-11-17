/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-28 19:39:15 by majesus           #+#    #+#             */
/*   Updated: 2026-11-11 16:05:17 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	a[8] = "abcdefg";
	char	b[8] = "abcdefg";
	size_t	i;

	bzero(a, 4);
	ft_bzero(b, 4);
	i = 0;
	while (i < 8)
	{
		printf("%d %d\n", a[i], b[i]);
		i++;
	}
	return (0);
}*/
//cc -Wextra -Wall -Werror ft_bzero.c ft_memset.c && ./a.out
