/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:21:42 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:56:31 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
int	main(void)
{
	char	*copy;

	copy = ft_strdup("Hello, world!");
	if (!copy)
		return (1);
	ft_putstr_fd(copy, 1);
	ft_putchar_fd('\n', 1);
	free(copy);
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_strdup
