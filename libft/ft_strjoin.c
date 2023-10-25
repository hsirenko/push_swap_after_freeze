/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:52:53 by hsirenko          #+#    #+#             */
/*   Updated: 2023/01/07 23:51:42 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*result;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	result = malloc(l1 + l2 + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, l1);
	ft_memcpy(result + l1, s2, l2 + 1);
	return (result);
}

/*int main(void)
{
	char s1[] = "string 1";
	char s2[] = "string 2";
	char *res = ft_strjoin(s1, s2);

	printf("new string is %s\n", res);
	free(res);
}*/