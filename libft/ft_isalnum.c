/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:37:55 by helensirenk       #+#    #+#             */
/*   Updated: 2023/02/06 22:55:23 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit (c))
		return (1);
	return (0);
}

/*int         main(void)
{
            int c = 66;
            char b = 'A';
            printf("%i\n", ft_isalnum(c));
            printf("%i\n", ft_isalnum(b));
}*/