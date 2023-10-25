/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:44:25 by hsirenko          #+#    #+#             */
/*   Updated: 2023/02/06 22:08:43 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1 = s1;
	const unsigned char	*p2 = s2;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char s1[] = "hello";
	char s2[] = "hello";

	int res;

	res = ft_memcmp(s1, s2, 4);
	if (res == 0)
	{
		printf("The strings are equal.\n");
	}
	else
	{
		printf("The strings are not equal.\n");
	}
	return (0);
}*/