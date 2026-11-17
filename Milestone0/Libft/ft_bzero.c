/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 19:39:15 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:54:26 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return ;
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
// cc -Wall -Wextra -Werror *.c -o test_ft_bzero
