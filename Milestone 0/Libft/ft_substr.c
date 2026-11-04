/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-04 16:04:07 by majesus           #+#    #+#             */
/*   Updated: 2026-11-04 16:04:07 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	while (s[i])
	{
		if (i == start)
		{
			while(start < len)
			{
				sub[start] = s[i];
				start++;
			}
		}
		i++;
	}
	sub[start] = '\0';
	return (sub);
}

int main(void)
{
	char	*s = "Hello World";
	printf("String principal: %s", s);
	char	*sub = ft_substr(s, 6, 5);
	printf("String sub: %s", sub);
}
