/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:56:45 by hsirenko          #+#    #+#             */
/*   Updated: 2023/02/06 21:36:04 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//converts a string to an integer
int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

/*int	main(int argc, char **argv)
{
	int first;
	int second;
	if (argc == 2)
	{
		first = ft_atoi(argv[1]);
		second = atoi(argv[1]);
		printf("first: %i | second: %i\n", first, second);
	}
	return (0);
}*/