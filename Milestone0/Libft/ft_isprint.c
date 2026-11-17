/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 19:13:53 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:54:55 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
int main(void)
{
	printf("%d\n", ft_isprint('5'));
	printf("%d\n", ft_isprint('a'));
	printf("%d\n", ft_isprint('Z'));
	printf("%d\n", ft_isprint('!'));
	printf("%d\n", ft_isprint(' '));
	printf("%d\n", ft_isprint(-1));
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_isprint
