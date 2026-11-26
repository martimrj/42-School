/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:42:53 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:55:33 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*a = ft_lstnew("Hello World");

	printf("content: %s\n", (char *)a->content);
	printf("next: %p\n", (void *)a->next);
	free(a);
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_lstnew
