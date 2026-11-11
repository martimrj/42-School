/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:19:32 by majesus           #+#    #+#             */
/*   Updated: 2026/11/11 18:33:59 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// void	maiuscula(unsigned int i, char *c)
// {
//     (void)i;
//     *c = ft_toupper(*c);
// }

// int	main(void)
// {
//     char	s[] = "abcd";

//     printf("String original: %s\n", s);
//     ft_striteri(s, maiuscula);
//     printf("String alterada: %s\n", s);
//     return (0);
// }
