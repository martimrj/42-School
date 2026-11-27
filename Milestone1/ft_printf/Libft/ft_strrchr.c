/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 14:52:26 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:56:56 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
	if ((unsigned char)s[0] == (unsigned char)c)
		return ((char *)&s[0]);
	if ((unsigned char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	return (NULL);
}
/*
int	main(void)
{
	char	*found;

	found = ft_strrchr("banana", 'a');
	if (found)
		ft_putendl_fd(found, 1);
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_strrchr
