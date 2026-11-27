/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 22:25:44 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:37:07 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i + ft_strlen(little) <= len)
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*found;

	found = ft_strnstr("libft functions", "fun", 15);
	if (found)
		ft_putendl_fd(found, 1);
	else
		ft_putendl_fd("Nao encontrado", 1);
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_strnstr
