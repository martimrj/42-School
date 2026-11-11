/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: o_teu_login <o_teu_login@student.42lisb    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 18:32:58 by majesus           #+#    #+#             */
/*   Updated: 2026/11/11 16:31:54 by o_teu_login      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *str, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(sizeof(char) * (n + 1));
	if (!(ptr))
		return (NULL);
	i = 0;
	while (i < n)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

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

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc(sizeof(*res) * (words + 1));
	j = 0;
	while (*s)
	{
		i = 0;
		while (*s == c)
			s++;
		if (*s)
		{
			while (s[i] != c && s[i])
				i++;
			res[j++] = ft_strndup(s, i);
		}
		s += i;
	}
	res[words] = NULL;
	return (res);
}

/*int main(int argc, char const *argv[])
{
	char **res;


	res = ft_split("   ", ' ');

	int i = 0;
	while (res[i])
	{
		printf(">%s<\n", res[i]);
		i++;
	}
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return 0;
}*/
