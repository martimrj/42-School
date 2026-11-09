/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majesus <marvin@42.fr>            			+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 18:32:58 by majesus           #+#    #+#             */
/*   Updated: 2026/11/09 21:33:42 by majesus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;          
	count = 0;      
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++; 
		i++;
	}
	return (count);
}

static char	*ft_word_dup(char const *s, size_t start, size_t len)
{
	char	*word;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + start, len + 1);
	return (word);
}

static int	ft_fill_split(char **split, char const *s, char c)
{
	size_t	i;  
	size_t	j; 
	size_t	start;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i; //index do início da palavra
		while (s[i] && s[i] != c)
			i++;
		len = i - start; //calculo do tamanho da palavra
		split[j] = ft_word_dup(s, start, len);
		if (!split[j])
			return (-1); 
		j++; 
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	words; 
	char	**split;

	if (!s || !c)
		return (NULL);
	words = ft_count_words(s, c); 
	split = malloc(sizeof(char *) * (words + 1)); 
	if (!split)
		return (NULL);
	if (ft_fill_split(split, s, c) == -1) 
		return (NULL);
	split[words] = NULL; 
	return (split); 
}

