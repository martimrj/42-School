/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 17:51:44 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:56:49 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
static char	shift_char(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}

int	main(void)
{
	char	*mapped;

	mapped = ft_strmapi("abc", shift_char);
	if (!mapped)
		return (1);
	ft_putendl_fd(mapped, 1);
	free(mapped);
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_strmapi
