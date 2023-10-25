/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:45:38 by hsirenko          #+#    #+#             */
/*   Updated: 2023/02/06 22:42:53 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)

{
	size_t		i;
	size_t		l_len;

	i = 0;
	if (little[0] == '\0' || little == NULL)
		return ((char *)big);
	while (i < len && big[i])
	{
		l_len = 0;
		while (little[l_len] == big[i + l_len] && i + l_len < len)
		{
			if (little[l_len + 1] == '\0')
			{
				return ((char *)big + i);
			}
			l_len++;
		}
		i++;
	}
	return (NULL);
}

/*int main(void)
{

		printf("%s",  ft_strnstr("abcdefgh", "abc", 2));
}*/