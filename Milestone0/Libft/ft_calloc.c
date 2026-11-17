/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 23:29:58 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 17:31:50 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
#include <stdio.h>
int	main(void)
{
	int		*a;
	size_t	i;

	a = ft_calloc(5, sizeof(int));
	i = 0;
	while (i < 5)
		printf("%d ", a[i++]);
	printf("\n");
	free(a);
	printf("overflow: %p\n", ft_calloc(SIZE_MAX, 2));
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_calloc
