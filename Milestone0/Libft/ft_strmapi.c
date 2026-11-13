/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 17:51:44 by majesus           #+#    #+#             */
/*   Updated: 2026/11/11 18:11:55 by majesus          ###   ########.fr       */
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
// char	Maisum(unsigned int i, char c)
// {
// 	(void)i;
// 	return (c + 1);
// }

// int	main(void)
// {
// 	char *str = "abcde";
// 	printf("String original: %s\n", str);
// 	printf("Strind alterada: %s\n", ft_strmapi(str, Maisum));
// }char	Maisum(unsigned int i, char c)
// {
// 	(void)i;
// 	return (c + 1);
// }

// int	main(void)
// {
// 	char *str = "abcde";
// 	printf("String original: %s\n", str);
// 	printf("Strind alterada: %s\n", ft_strmapi(str, Maisum));
// }
