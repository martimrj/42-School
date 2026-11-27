/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:54:12 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:55:10 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>

static void	noop(void *content)
{
	(void)content;
}

int	main(void)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = NULL;
	a = ft_lstnew("a");
	b = ft_lstnew("b");
	if (!a || !b)
		return (1);
	ft_lstadd_front(&head, a);
	printf("vazia: %d\n", head == a && a->next == NULL);
	ft_lstadd_front(&head, b);
	printf("ordem: %d\n", head == b && b->next == a);
	ft_lstclear(&head, noop);
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_lstadd_front
