/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:43:21 by hsirenko          #+#    #+#             */
/*   Updated: 2023/01/26 18:19:36 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(const char *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	if (!s[0])
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			word++;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		word++;
	return (word);
}

char	**ft_free(char **s, size_t start)
{
	size_t	i;

	i = 0;
	while (i < start)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	size_t			len;
	size_t			start;

	start = 0;
	if (!s)
		return (NULL);
	str = (malloc(sizeof(char *) * (ft_wordcount(s, c) + 1)));
	if (!str)
		return (0);
	while (*s++)
	{
		if (*(s - 1) != c && --s)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			str[start] = ft_substr(s - len, 0, len);
			if (!str[start])
				return (ft_free(str, start));
			start++;
		}
	}
	str[start] = 0;
	return (str);
}

int main ()
{
	char const *s = "String split and something else and soso and saba ass";
	char c;
	
	c = 's';
	char* result = *ft_split(s, c);
	printf("Initial string: %s\n Split string: %s\n", s, result);
}

// create new array of arrays;
/* move each char,
How to define the number of all resulting strings */
/*please shut up*/