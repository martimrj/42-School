/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:10:26 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:54:37 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*
int main(void)
{
	printf("%d\n", ft_isalnum('5'));
	printf("%d\n", ft_isalnum('a'));
	printf("%d\n", ft_isalnum('Z'));
	printf("%d\n", ft_isalnum('!'));
	printf("%d\n", ft_isalnum(' '));
	printf("%d\n", ft_isalnum(5));
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_isalnum
