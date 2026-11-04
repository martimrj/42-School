/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-02 21:44:26 by majesus           #+#    #+#             */
/*   Updated: 2026-11-02 21:44:26 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*string1;
	const unsigned char	*string2;

	string1 = (const unsigned char *)s1;
	string2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while(i < n && (string1[i] == string2[i]))
	{
		i++;
	}
	if (i == n)
		return (0);
	return (string1[i] - string2[i]);
}
