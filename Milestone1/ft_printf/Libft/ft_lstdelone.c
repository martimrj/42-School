/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 20:26:18 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 16:55:18 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*a = ft_lstnew(ft_strdup("Hello"));

	printf("antes: %s\n", (char *)a->content);
	ft_lstdelone(a, free);
	return (0);
}*/
// cc -Wall -Wextra -Werror *.c -o test_ft_lstdelone
