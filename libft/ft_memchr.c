/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:14:49 by hsirenko          #+#    #+#             */
/*   Updated: 2022/12/30 19:30:56 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/*The  memchr()  function  scans  the  initial n bytes of the memory area
       pointed to by s for the first instance of c.  Both c and the  bytes  of
       the memory area pointed to by s are interpreted as unsigned char.
	   The  memchr() function returns a pointer to the matching
       byte or NULL if the character does not occur in the given memory area.

*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*strt_s;
	unsigned char		cser;

	strt_s = (unsigned char *)s;
	cser = c;
	i = 0;
	while (i < n)
	{
		if (strt_s[i] == cser)
			return ((void *)(strt_s + i));
		i++;
	}
	return (NULL);
}

/*int main(void)
{
    char str[] = "Hello, world!";
    char* p = ft_memchr(str, 'l', sizeof(str));
    if (p)
    {
        printf("Found 'l' at index %ld\n", p - str);
    }
    else
    {
        printf("Did not find 'l'\n");
    }
    return 0;
}*/
