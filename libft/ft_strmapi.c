/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:26:12 by hsirenko          #+#    #+#             */
/*   Updated: 2023/02/04 18:23:53 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_custom(unsigned int num, char let)
{
	while (num)
	{
		let += 2;
		return (let);
	}
	if (num == 0)
		let += 2;
	return (let);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s || f == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (int)ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*int main(void)
{
	char *str = "star";
	//unsigned int num = 2;
	//char let = 'a';
	char *newstr = ft_strmapi(str, ft_custom);
	printf("%s\n", newstr);
	
}*/