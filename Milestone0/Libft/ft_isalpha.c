/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:35:04 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:54:43 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_isalpha('5'));
	printf("%d\n", ft_isalpha('a'));
	printf("%d\n", ft_isalpha('Z'));
	printf("%d\n", ft_isalpha('!'));
	printf("%d\n", ft_isalpha(' '));
	printf("%d\n", ft_isalpha(5));
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_isalpha
