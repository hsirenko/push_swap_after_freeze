/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:58:02 by hsirenko          #+#    #+#             */
/*   Updated: 2023/01/26 17:55:55 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			end;
	char			*str;

	str = 0;
	if (s1 && set)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strrchr(set, s1[start]))
			start++;
		while (s1[end - 1] && ft_strrchr(set, s1[end - 1]) && end > start)
			end--;
		str = (char *)malloc(sizeof(char) * (end - start + 1));
		if (str)
		{
			ft_strlcpy(str, &s1[start], end - start + 1);
		}
	}
	return (str);
}

/*int main(void)
{
	char s1[35] = "abcadbsabbaThis is a full stringab";
	char s2[20] = "abcdef";

	char* result = ft_strtrim(s1, s2);
	printf("%s\n", result);
	free (result);
}*/
