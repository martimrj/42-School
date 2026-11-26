/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 15:31:48 by majesus           #+#    #+#             */
/*   Updated: 2026/11/26 16:15:18 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINT_H

# include "Libft/libft.h"
# include	<stdarg.h>

int	ft_printf(const char *fmt, ...);
int	ft_printf_char(char c);
int ft_printf_str(char *str);
int ft_printf_base(unsigned long nb, char *d);
int ft_printf_ptr(void *nbr);
int ft_printf_nbr(unsigned int nbr);

#endif
