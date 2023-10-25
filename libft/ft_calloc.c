/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:57:01 by hsirenko          #+#    #+#             */
/*   Updated: 2023/02/06 22:14:24 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;

	str = malloc(nmemb * size);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
