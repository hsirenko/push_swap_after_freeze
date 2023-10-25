/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:31:41 by hsirenko          #+#    #+#             */
/*   Updated: 2023/02/05 22:01:20 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
		c++;
	}
	if (!(c >= 'a' && c <= 'z'))
	{
		return (c);
	}
	return (c);
}

/*int main(void)
{
    char c = 'a';
    printf("Lowercase: %c\n", c);
    printf("Uppercase: %c\n", ft_toupper(c));

    return 0;
}*/