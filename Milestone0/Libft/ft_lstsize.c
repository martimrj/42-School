/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:58:41 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 13:33:32 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*
# include <stdio.h>

int main(void)
{
	t_list *a = ft_lstnew("A");
	t_list *b = ft_lstnew("B");

	ft_lstadd_back(&a, b);
	printf("Tamanho: %u\n", ft_lstsize(a));
	free(a);
	return (0);
}*/
//cc -Wall -Wextra -Werror ft_lstsize.c ft_lstnew.c ft_lstadd_back.c
