/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-29 20:04:42 by majesus           #+#    #+#             */
/*   Updated: 2026-10-29 20:04:42 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if(str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if((char)c == '\0')
		return((char *)&str[i]);
	return (NULL);
}
// int main (void)
// {
// 	char	a[] = "aaba";
// 	char	*n;

// 	printf("%s\n", a);
// 	n = ft_strchr(a, 'b');
// 	printf("%s", n);

// }
