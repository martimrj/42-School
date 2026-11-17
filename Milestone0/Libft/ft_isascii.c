/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:40:23 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:54:46 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int main(void)
{
	printf("%d\n", ft_isascii('5'));
	printf("%d\n", ft_isascii('a'));
	printf("%d\n", ft_isascii('Z'));
	printf("%d\n", ft_isascii('!'));
	printf("%d\n", ft_isascii(' '));
	printf("%d\n", ft_isascii(-1));
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_isascii
