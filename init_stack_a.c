/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 01:12:54 by hsirenko          #+#    #+#             */
/*   Updated: 2023/09/18 18:38:23 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	init_stack_a(t_stack_node **a, char **argv, bool argc_2)
{
	int		i;
	long	nb;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, argc_2);
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error_free(a, argv, argc_2);
		if (error_repetition(*a, nb))
			error_free(a, argv, argc_2);
		append_node(a, nb);
		i++;
	}
	if (argc_2)
		free_2d_array(argv);
}

//int main()
//{
//	t_stack_node *a;
//
//	a = NULL;
//	char *v[5] = {v[0] = "\0", v[1] = "42",
//	v[2] = "1337", v[3] = "-21", v[4] = NULL};
//	init_stack_a(&a, v+1);
//
//
//	while (a)
//	{
//		printf("\n%d,\tnode with address %p\n", a->val, a);
//		a = a->next;
//	}
//}