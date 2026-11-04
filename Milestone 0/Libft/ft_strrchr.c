/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 14:52:26 by majesus           #+#    #+#             */
/*   Updated: 2026-10-30 14:52:26 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if((char)c == '\0')
		return((char *)&s[i]);
	while(i >= 0)
	{
		if(s[i] == (char)c)
			return ((char *)(&s[i]));
		i--;
	}
	return (NULL);
}