/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:13:27 by hsirenko         #+#    #+#             */
/*   Updated: 2023/09/17 15:20:27 by hsirenko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2d_array(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv - 1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	current = *stack;
	if (NULL == stack)
		return ;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

int	error_repetition(t_stack_node *a, int nb)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->val == nb)
		{
			return (1);
		}
		a = a->next;
	}
	return (0);
}

void	error_free(t_stack_node **a, char **argv, bool argc_2)
{
	free_stack(a);
	if (argc_2)
		free_2d_array(argv);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

int	error_syntax(char *str)
{
	if (!(str[0] == '+' || str[0] == '-' || (str[0] >= '0' && str[0] <= '9')))
		return (1);
	if ((str[0] == '+' || str[0] == '-') && (!(str[1] >= '0' && str[1] <= '9')))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}
//int main(void)
//{
//	t_stack_node * a;
//
//	a = NULL;
//	a = malloc(sizeof(t_stack_node));
//	a -> next = malloc(sizeof(t_stack_node));
//	a -> next -> next = malloc(sizeof(t_stack_node));
//	a -> val = 42;
//	a -> next -> val = -134;
//	a -> next -> next -> val = 3;
//	a -> prev = NULL;
//	a -> next -> prev = a;
//	a -> next -> next -> prev = a -> next;
//	a -> next -> next -> next = NULL;
//	repetition_check(a, 42);
//	print_stack(a);
//	free_stack(&a);
//}
//	(void) argc;
//	int i = 0;
//	*argv = "1, 2, 3";
//	ft_split(*argv, ' ');
//
//	while (argv[i])
//	{
//		printf("%s\n", argv[i]);
//		i++;
//	}
//	free_2d_array(argv);