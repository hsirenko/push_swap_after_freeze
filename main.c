/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:45:33 by hsirenko         #+#    #+#             */
/*   Updated: 2023/09/17 18:45:33 by hsirenko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				len_a;

	a = NULL;
	b = NULL;
	len_a = stack_len(a);
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	else if (2 == argc)
		argv = f_split(argv[1], ' ');
	init_stack_a(&a, argv + 1, 2 == argc);
	if (!stack_sorted(a))
	{
		if (len_a == 2)
			sa(&a, false);
		else if (len_a == 3)
			sort_three(&a);
		else
			stack_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
