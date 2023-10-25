/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:21:25 by hsirenko          #+#    #+#             */
/*   Updated: 2023/01/26 22:55:56 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lenint(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i = i + 1;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*result;
	const char	*digits;

	digits = "0123456789";
	len = ft_lenint(n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = 0;
	if (n == 0)
		result[0] = '0';
	if (n < 0)
		result[0] = '-';
	while (n != 0)
	{
		if (n > 0)
			result[--len] = digits[n % 10];
		else
			result[--len] = digits[n % 10 * -1];
		n /= 10;
	}
	return (result);
}

/*int main(void)
{
	printf("\n%s\n", ft_itoa(10050003));
	
}*/