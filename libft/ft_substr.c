/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:06:21 by hsirenko          #+#    #+#             */
/*   Updated: 2023/01/26 18:19:16 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) <= len)
		len = ft_strlen(s + start);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

/* 
	str = "hello, world"
	start = 5
	len = 10

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	length;
	unsigned int	i;
	char *substr;
	
	if (!(s))
		return (NULL);
	length = ft_strlen((char *)s);
	if (start > (size_t)length)
	{
		if (!(substr = malloc(sizeof(char) * 1)))
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (start > length)
		return (ft_strdup(""));
	//if (start > length || length < start + (unsigned int)len)
		//return(substr);
	substr = (char)malloc(sizeof(char) * ((unsigned int)len + 1));
	if (!(substr))
		return (NULL);
	i = 0;
	while ((s[start] != '\0') && i < (unsigned int)len)
	{
		substr[i] = s[start + i];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}*/

/*int main(void)
{
	printf("str: %s, substr: %s\n", "dfk", ft_substr("d", 12, 6));
	return (0);
	//char *str = "i just want this part #############";
 	//size_t size = 22;
	//char *largerstr = "Baby, is that true?";
	//char *smallerstr = "Baby";
 	char *ptr = ft_substr("hola", 0, 4);
	printf("|%s|\n", ptr);
	if (ptr != NULL)
	{
		printf("'%s' found in '%s'\n", smallerstr, largerstr);
	}
	else
	{
		printf("'%s' not found in '%s'\n", smallerstr, largerstr);
	}
}
*/