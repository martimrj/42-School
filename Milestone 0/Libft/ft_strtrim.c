/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-04 20:15:48 by majesus           #+#    #+#             */
/*   Updated: 2026-11-04 20:15:48 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	size_t	start;
	size_t	end;
	size_t	i;
	size_t len;

	if(!s1 || !set)
		return (NULL);
	start = 0;
	i = 0;
	while (s1[start])
	{
		if (ft_strchr(s1, set[i]))
			break;
		start++;
	}
	end = ft_strlen(s1) - 1;
	while (s1[end])
	{
		if (ft_strchr(s1, set[i]))
			break;
		end--;
	}
	len = end - start;
	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	return ((char *)(cpy));
}

int main (void)
{
	char const *s1 = "xxaaxy";
	char const *set = "x";
	char *s2 = ft_strtrim(s1, set);
	printf("String inicial: %s", s2);
	printf("String final: %s", s2);
	free(s2);
}
