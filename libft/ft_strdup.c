/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:06:56 by hsirenko          #+#    #+#             */
/*   Updated: 2023/01/15 20:17:55 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//The strdup() function returns a pointer to a new string 
//which is a duplicate of the string s.  Memory for the new string is ob‐
//tained with malloc(3), and can be freed with free(3).

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(dup))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*int main(void)
{
	char *original = "lorem ipsum dolor sit amet";
	char *copy = ft_strdup(original);

	printf("%s\n", copy);
	free(copy);
}*/