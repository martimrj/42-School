/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 20:26:18 by majesus           #+#    #+#             */
/*   Updated: 2026/11/17 13:16:13 by majesus          ###   ########.fr       */
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
	printf("depois: %s\n", (char *)a->content);
	return (0);
}*/
//cc -Wall -Wextra -Werror ft_lstdelone.c ft_lstnew.c
