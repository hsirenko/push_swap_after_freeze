/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:39:01 by hsirenko          #+#    #+#             */
/*   Updated: 2023/02/05 22:02:20 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
		c++;
	}
	if (!(c >= 'A' && c <= 'A'))
	{
		return (c);
	}
	return (c);
}

/*int main(void)
{
    char c = 'A';
    printf("Uppercase: %c\n", c);
    printf("Lowercase: %c\n", ft_tolower(c));

    return 0;
}*/