/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus	<majesus@student.42lisboa 	  	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 18:32:58 by majesus           #+#    #+#             */
/*   Updated: 2026/11/11 16:31:54 by majesus	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		while (*s != c && *s)
			s++;
	}
	return (words);
}

static void	*free_all(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static char	**fill_words(char **res, char const *s, char c)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			i = 0;
			while (s[i] && s[i] != c)
				i++;
			res[j] = ft_substr(s, 0, i);
			if (!res[j])
				return (free_all(res));
			j++;
			s += i;
		}
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	return (fill_words(res, s, c));
}
// int main(int argc, char const *argv[])
// {
// 	char **res;
// 	res = ft_split("   ", ' ');

// 	int i = 0;
// 	while (res[i])
// 	{
// 		printf(">%s<\n", res[i]);
// 		i++;
// 	}
// 	while (res[i])
// 	{
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// 	return 0;
// }
