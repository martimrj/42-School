/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-10-30 17:08:53 by majesus           #+#    #+#             */
/*   Updated: 2026-10-30 17:08:53 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] == s2[i]) && s1[i])
	{
		i++;
	}
	if (n == i)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
// int	main(void)
// {
// 	const char *str1 = "Hello, World!";
// 	const char *str2 = "Hello, Universe!";
// 	size_t n = 12;

// 	int result = ft_strncmp(str1, str2, n);
// 	if (result < 0)
// 		printf("'%s' is less than '%s' up to %zu characters.\n", str1, str2, n);
// 	else if (result > 0)
// 		printf("'%s' is greater than '%s' up to %zu characters.\n", str1, str2, n);
// 	else
// 		printf("'%s' is equal to '%s' up to %zu characters.\n", str1, str2, n);

// 	return 0;
// }
