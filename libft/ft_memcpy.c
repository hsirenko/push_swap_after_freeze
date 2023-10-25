/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 02:07:49 by helensirenk       #+#    #+#             */
/*   Updated: 2023/01/07 23:39:00 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

/*int main(void)
{
	char str1[] = "source";
	char str2[] = "dest";

	printf("str before ft_memcpy %s\n", str1);

	char *res = ft_memcpy(str2, str1, sizeof(str2));
	printf("\nstr after ft_memcpy %s\n", res);
}*/