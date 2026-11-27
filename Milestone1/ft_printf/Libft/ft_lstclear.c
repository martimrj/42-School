/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 21:48:30 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:55:15 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*a = ft_lstnew(ft_strdup("A"));

	ft_lstadd_back(&a, ft_lstnew(ft_strdup("B")));
	printf("a: %s\n", (char *) a -> content);
	printf("a: %s\n", (char *) a -> next -> content);
	ft_lstclear(&a, free);
	printf("a: %p\n", (void *)a);
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_lstclear
