/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:58:33 by hsirenko          #+#    #+#             */
/*   Updated: 2023/02/06 17:45:29 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		if (*s1 == '\0' || *s2 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (0);
}

/*int	main(void)
{
	char s1[] = "compare1";
	char s2[] = "compare2";
	
	printf("%i\n", ft_strncmp(s1, s2, 10));
	printf("%i\n", ft_strncmp(s1, s2, 10));
	printf("%i\n", ft_strncmp("test", "", 0));
	printf("%i\n", ft_strncmp("abcdef", "abc\375xx", 5));
	return (0);
}*/