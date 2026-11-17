/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 20:05:51 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 12:28:16 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
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
	ft_lstadd_back(&head, a);
	printf("vazia: %d\n", head == a);
	ft_lstadd_back(&head, b);
	printf("ordem: %d\n", head->next == b && b->next == NULL);
	ft_lstclear(&head, noop);
	return (0);
}*/
//cc -Wall -Wextra -Werror ft_lstadd_back.c ft_lstnew.c ft_lstclear.c
