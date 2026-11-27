/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:54:37 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:54:51 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_isdigit('5'));
	printf("%d\n", ft_isdigit('a'));
	printf("%d\n", ft_isdigit('Z'));
	printf("%d\n", ft_isdigit('!'));
	printf("%d\n", ft_isdigit(' '));
	printf("%d\n", ft_isdigit(-1));
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_isdigit
