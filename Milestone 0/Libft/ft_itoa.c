/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <majesus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 23:15:00 by majesus           #+#    #+#             */
/*   Updated: 2026/11/09 23:43:41 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *invert_string(char  *str, int len)
{
    size_t  start;
    size_t  end;
    char    temp;

    start = 0;
    end = len - 1;
    while (start < len)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;        
    }
    return (str); 
}

char *ft_itoa(int n)
{
    int temp;
    int i;
    int signal;
    int len;
    char *str;

    temp = n;
    signal = 0;
    len = 0;
    i = 0;

    if (n < 0)
    {
        signal = 1;
        temp = -n;
    }
    while (temp > 0)
    {
        len++;
        temp /= 10;
    }

    str = malloc(len + signal + 1);
    if (!str)
        return (NULL);

    temp = n;
    if (temp < 0)
        temp = -temp;

    while (temp > 0)
    {
        str[i] = (temp % 10) + '0';
        temp /= 10;
        i++;
    }

    if (signal == 1)
        str[i++] = '-';

    str[i] = '\0';
    invert_string(str, i);
    return (str);
}
