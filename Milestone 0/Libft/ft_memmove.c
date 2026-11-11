/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: o_teu_login <o_teu_login@student.42lisb    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 20:17:50 by majesus           #+#    #+#             */
/*   Updated: 2026/11/11 16:26:34 by o_teu_login      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*destiny;
	const unsigned char		*source;
	size_t					i;

	if (dest == NULL && src == NULL)
		return (NULL);
	destiny = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	i = n;
	while (i > 0)
	{
		i--;
		destiny[i] = source[i];
	}
	return (dest);
}
