/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: o_teu_login <o_teu_login@student.42lisb    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:02:39 by majesus           #+#    #+#             */
/*   Updated: 2026/11/11 16:36:08 by o_teu_login      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length_dst;
	size_t	length_src;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (0);
	length_dst = ft_strlen(dst);
	length_src = ft_strlen(src);
	if (size <= length_dst)
		return (size + length_src);
	i = 0;
	while (src[i] && length_dst + i + 1 < size)
	{
		dst[length_dst + i] = src[i];
		i++;
	}
	dst[length_dst + i] = '\0';
	return (length_dst + length_src);
}
