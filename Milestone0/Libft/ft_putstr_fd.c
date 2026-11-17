/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa> 	    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:58:41 by majesus           #+#    #+#             */
/*   Updated: 2026/11/11 19:01:16 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, &*s, 1);
		s++;
	}
}
/*
int	main(void)
{
	ft_putstr_fd("Ola, libft!\n", 1);
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_putstr_fd
