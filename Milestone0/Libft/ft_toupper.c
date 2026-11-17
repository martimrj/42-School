/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 20:02:54 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 18:12:34 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*int	main(void)
{
	ft_putchar_fd(ft_toupper('a'), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_toupper
