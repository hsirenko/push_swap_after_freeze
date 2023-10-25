/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:00:52 by hsirenko          #+#    #+#             */
/*   Updated: 2023/02/06 22:58:08 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	p = NULL;
	i = 0;
	if (s[0] == '\0' && c != '\0')
		return (NULL);
	i = ft_strlen(s);
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
		{
			p = ((char *)&s[i]);
			return (p);
		}
		i--;
	}
	return (NULL);
}

/*int main()
{
	char s[] = "Hello, world!";
	char *p;

	p = ft_strrchr(s, 'l');
	printf("%s\n", p);

	return 0;
}*/

/*    The strrchr() function returns a pointer to the last occurrence of  the
	   character c in the string s.
The strchr() and strrchr() functions return a pointer  to  the  matched
	   character  or NULL if the character is not found.  The terminating null
	   byte is considered part of the string, so that if  c  is  specified  as
	   '\0', these functions return a pointer to the terminator.
*/