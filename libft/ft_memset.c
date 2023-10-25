/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:25:46 by helensirenk       #+#    #+#             */
/*   Updated: 2022/12/29 13:24:38 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

// Sets the first len characters of b to the value c. memset returns b.
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len > 0)
	{
		*p = (unsigned char)c;
		p++;
		len--;
	}
	return (b);
}

/*int         main(void)
{
            char str[70] = "This is a long string to be filled out.";
            printf("Before memset(): %s\n", str);

            ft_memset(str + 2, '.', 8 * sizeof(char));
            printf("After ft_memset(); %s\n", str);
}*/