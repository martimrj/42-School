/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 20:02:59 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:55:26 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*lista = ft_lstnew("C");

	ft_lstadd_front(&lista, ft_lstnew("B"));
	ft_lstadd_front(&lista, ft_lstnew("A"));
	printf("ft_lstlast: %s\n", (char *)ft_lstlast(lista)->content);
	free(lista->next->next);
	free(lista->next);
	free(lista);
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_lstlast
