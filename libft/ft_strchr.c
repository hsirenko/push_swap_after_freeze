/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:07:10 by hsirenko          #+#    #+#             */
/*   Updated: 2023/02/06 22:10:53 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;
	char			*p;

	p = NULL;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == str[i])
		return ((char *)&str[i]);
	return (p);
}
/*int main(void)
{
    char str[] = "Hello, World!";
    char *ptr;

    ptr = ft_strchr(str, 'W');
    if (ptr) {
        printf("Character 'W' found at index %ld\n", ptr - str);
    } else {
        printf("Character 'W' not found\n");
    }

    return 0;
}*/