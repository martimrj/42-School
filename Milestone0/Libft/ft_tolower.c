/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 20:04:10 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:52:47 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Converte uma letra maiúscula ASCII para minúscula. */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
int	main(void)
{
	ft_putchar_fd(ft_tolower('Z'), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_tolower
