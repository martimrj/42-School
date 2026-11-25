/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 15:31:48 by majesus           #+#    #+#             */
/*   Updated: 2026/11/25 17:34:00 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINT_H

# include "Libft/libft.h"
# include	<stdarg.h>

int	ft_printf(const char *fmt, ...);
int	ft_printf_c(char c);
int ft_printf_str(char *str);
int ft_printf_hex(unsigned long nb, char c);
int ft_printf_dec_int(int nbr);
int ft_printf_u(unsigned int nbr);
int ft_printf_ptr(void *ptr);

#endif
