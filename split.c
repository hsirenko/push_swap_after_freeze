/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                             :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.de>      +#+  +:+       +#+        	  */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:45:33 by hsirenko         #+#    #+#             */
/*   Updated: 2023/09/17 18:45:33 by hsirenko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			s++;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	int			len;
	int			i;
	static int	cursor = 0;
	char		*next_word;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**f_split(char *s, char c)
{
	int		wc;
	char	**result;
	int		i;

	i = 0;
	wc = word_count(s, c);
	if (!wc)
		exit(1);
	result = malloc(sizeof(char *) * (size_t)(wc + 2));
	if (!result)
		return (NULL);
	while (wc-- >= 0)
	{
		if (i == 0)
		{
			result[i] = malloc(sizeof(char));
			if (!result[i])
				return (NULL);
			result[i++][0] = '\0';
			continue ;
		}
		result[i++] = get_next_word(s, c);
	}
	result[i] = NULL;
	return (result);
}

//char	*ft_strcpy(char *s1, char *s2, int n)
//{
//	int i = 0;
//	while (s2[i] && i < n)
//	{
//		s1[i] = s2[i];
//		i++;
//	}
//	s1[i] = '\0';
//	return(s1);
//}
//
//char	**f_split(char *str, char space)
//{
//	int i = 0;
//	int j;
//	int wc = 0;
//	int start;
//	int end;
//
//	space = ' ';
//
//	j = 0;
//
//
//	while (str[i])
//	{
//		while (str[i] && (str[i] == space || str[i] == '\n' || str[i] == '\t'))
//			i++;
//		if (str[i])
//			wc++;
//		while (str[i] && (str[i] != space && str[i] != '\n' && str[i] != '\t'))
//			i++;
//	}
//	char **result = (char **)malloc(sizeof(char *) * (wc + 2));
//		if (!result)
//			return (NULL);
//	end = 0;
//	while (str[end])
//	{
//		while (str[end] && (str[end] == space
//		|| str[end] == '\n' || str[end] == '\t'))
//			end++;
//		start = end;
//		while (str[end] && (str[end] != space
//		&& str[end] != '\n' && str[end] != '\t'))
//			end++;
//		if (end > start)
//		{
//			result[j] = (char *)malloc(sizeof(char) * ((end - start) + 2));
//			if (!result[j])
//				return (NULL);
//			ft_strcpy(result[j++], &str[start], end - start);
//		}
//	}
//	result[j] = NULL;
//	return (result);
//}

//int main()
//{
//	char *str1 = "    Hello. This   is a test    .  ";
//	char *str = "1  2 3 5";
//	char space = ' ';
//	char **result = f_split(str, space);
//	int i = 0;
//
//	while (result[i])
//	{
//		printf("Word %d: %s\n", i, result[i]);
//		free(result[i]);
//		i++;
//	}
//	free(result);
//	return (0);
//
//	char *s2 = "Hello";
//	char s1[6];
//	int n = 6;
//	printf("%s", ft_strcpy(s1, s2, n));
//}