/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 01:12:54 by hsirenko          #+#    #+#             */
/*   Updated: 2023/09/18 18:38:23 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->val > stack->next->val)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_stack_node	*find_highest(t_stack_node *stack)
{
	int				highest;
	t_stack_node	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->val > highest)
		{
			highest = stack->val;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a, false);
	if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->val > (*a)->next->val)
		sa(a, false);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	while (len_a-- > 3)
	{
		init_nodes(*a, *b);
		fin_rot(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}

//int main()
//{
//	t_stack_node *a;
//
//	a = NULL;
//	a = malloc(sizeof(t_stack_node));
//	a->val = 1;
//	a->prev = NULL;
//	a->next = NULL;
//
//	a->next = malloc(sizeof(t_stack_node));;
//	a->next->val = 3;
//	a->next->prev = a;
//	a->next->next = NULL;
//
//
//	a->next->next = malloc(sizeof(t_stack_node));
//	a->next->next->val = 2;
//	a->next->next->prev = a->next;
//	a->next->next->next = NULL;
//
//	a->next->next->next = malloc(sizeof(t_stack_node));
//	a->next->next->next->val = 88;
//	a->next->next->next->prev = a->next->next;
//	a->next->next->next->next = NULL;
//
//	a->next->next->next->next = malloc(sizeof(t_stack_node));
//	a->next->next->next->next->val = 55;
//	a->next->next->next->next->prev = a->next->next->next;
//	a->next->next->next->next->next = NULL;
//
//	//current_index(a);
//
//	t_stack_node *b = malloc(sizeof(t_stack_node));
//	b->val = 0;
//	b->prev = NULL;
////
////	b->next = malloc(sizeof(t_stack_node));
////	b->next->val = 100;
////	b->next->prev = b;
////	//b->next->next = NULL;
////
////	b->next->next = malloc(sizeof(t_stack_node));
////	b->next->next->val = 1000;
////	b->next->next->prev = b->next;
////	b->next->next->next = NULL;
//
////	current_index(a);
////	current_index(b);
////	target_node(a, b);
////	push_price(a, b);
//	//find_cheapest(b);
//
//	//rotate_both(&a, &b, false);
//	//move_nodes(&a, &b);
//
//
//	printf("Before sort: ");
//	printf("a1->val %d\n", a->val);
//	printf("a2->val %d\n", a->next->val);
//	printf("a3->val %d\n", a->next->next->val);
//	printf("a4->val %d\n", a->next->next->next->val);
//	printf("a5->val %d\n", a->next->next->next->next->val);
//
//	sort_five(&a, &b);
//	//stack_sort(&a, &b);
//	//move_nodes(&a, &b);
//
//	printf("After sort: ");
//	printf("a1->val %d\n", a->val);
//	printf("a2->val %d\n", a->next->val);
//	printf("a3->val %d\n", a->next->next->val);
//	printf("a4->val %d\n", a->next->next->next->val);
//	printf("a5->val %d\n", a->next->next->next->next->val);
//
//	free(a);
//	//free(b);
//}
