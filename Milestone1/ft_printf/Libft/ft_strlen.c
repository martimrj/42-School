/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 19:17:30 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:31:10 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	ft_putnbr_fd((int)ft_strlen("libft"), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_strlen
