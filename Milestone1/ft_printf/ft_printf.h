/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 15:31:48 by majesus           #+#    #+#             */
/*   Updated: 2026/11/27 21:41:55 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include "Libft/libft.h"

int	ft_printf(const char *fmt, ...);
int	ft_printf_char(char c);
int	ft_printf_str(char *str);
int	ft_printf_base(unsigned long nb, const char *digits);
int	ft_printf_ptr(void *ptr);
int	ft_printf_nbr(int nbr);
int	ft_printf_unsigned(unsigned int nbr);

#endif
