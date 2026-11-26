/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 21:55:28 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:58:02 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>

void	f(void *c)
{
	printf("f: %s\n", (char *)c);
}

int	main(void)
{
	t_list	*a = ft_lstnew("1");
	t_list	*b = ft_lstnew("2");
	t_list	*c = ft_lstnew("3");

	ft_lstadd_back(&a, b);
	ft_lstadd_back(&a, c);
	ft_lstiter(a, f);
	free(c);
	free(b);
	free(a);
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_lstiter
