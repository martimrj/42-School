/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 12:25:59 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 13:03:29 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
#include <stdio.h>

void	*f(void *c)
{
	return (ft_strdup((char *)c));
}

int	main(void)
{
	t_list	*a = ft_lstnew(ft_strdup("A"));
	t_list	*b;

	ft_lstadd_back(&a, ft_lstnew(ft_strdup("B")));
	b = ft_lstmap(a, f, free);
	printf("b: %s\n", (char *)b->content);
	printf("b: %s\n", (char *)b->next->content);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}*/
//cc -Wall -Wextra -Werror ft_lstmap.c ft_lstadd_back.c ft_lstnew.c ft_lstclear.c ft_strdup.c ft_strlen.c

