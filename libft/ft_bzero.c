/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:46:35 by helensirenk       #+#    #+#             */
/*   Updated: 2023/01/03 18:38:58 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>
#include "libft.h"

// The bzero() function writes n zeroed bytes 
// to the string s.  If n is zero, bzero() does nothing.
// All bzero() does 
//is memset everything to zero. 
void	ft_bzero(void *s, size_t n)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

/*int	main(void)
{
	char str[50] = "Test test";
	ft_bzero(str, sizeof(char));
	printf("After ft_bzero(): %s\n", str);
}*/