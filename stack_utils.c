/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 01:37:59 by hsirenko          #+#    #+#             */
/*   Updated: 2023/09/18 18:05:27 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
	{
		head = head->next;
	}
	return (head);
}

void	append_node(t_stack_node **stack, int nb)
{
	t_stack_node	*appending_node;
	t_stack_node	*last_node;

	appending_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	appending_node->val = nb;
	appending_node->next = NULL;
	if (NULL == stack)
		return ;
	if (NULL == *stack)
	{
		*stack = appending_node;
		appending_node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = appending_node;
		appending_node->prev = last_node;
	}
}

int	stack_len(t_stack_node *stack)
{
	int	count;

	count = 0;
	if (NULL == stack)
		return (0);
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_stack_node	*find_smallest(t_stack_node *stack)
{
	t_stack_node	*smallest_node;
	long			min;

	min = LONG_MAX;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->val < min)
		{
			min = stack->val;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

//int main()
//{
//	t_stack_node *a;
//
//	a = NULL;
//	a = malloc(sizeof(t_stack_node));
//	a->val = 4;
//	a->prev = NULL;
//	a->next =  malloc(sizeof(t_stack_node));;
//	a->next->val = 12;
//	a->next->prev = a;
//	a->next->next = NULL;
//
//	t_stack_node *smallest;
//	smallest = find_smallest(a);
//	printf("smallest is: %d", smallest->val);

//	printf("Before rotate: ");
//	printf("a-> val %d\n", a->val);
//	printf("a->next -> val %d\n", a->next->val);
//
//	ra(&a, false);
//
//	printf("After rotate: ");
//	printf("a-> val %d\n", a->val);
//	printf("a->next -> val %d\n", a->next->val);

//	free(a);
//
//}

//int main()
//{
//	    t_stack_node *a;
//
//	    a = NULL;
//	    //char *v[5] = {v[0] = "\0", v[1] = "42", v[2] = "1337",
//	    v[3] = "-21", v[4] = NULL};
//	append_node(&a, 1000);
//	append_node(&a, 5);
//
//    while (a)
//	{
//
//        printf("\n%d, \tnode with address %p\n", a->val, a);
//		a = a->next;
//
//	}
//}