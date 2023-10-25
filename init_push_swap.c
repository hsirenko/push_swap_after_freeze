/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:24:38 by hsirenko          #+#    #+#             */
/*   Updated: 2023/10/19 01:43:26 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	target_node(t_stack_node *a, t_stack_node *b)

{
	t_stack_node	*target_node;
	t_stack_node	*current_a;
	long			best_match_index;

	while (b)
	{
		current_a = a;
		best_match_index = LONG_MAX;
		while (current_a)
		{
			if (current_a->val > b->val && current_a->val < best_match_index)
			{
				best_match_index = current_a->val;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	current_index(t_stack_node *stack)
{
	int		median;
	int		index;

	index = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_index = index;
		if (index <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		index++;
	}
}

void	push_price(t_stack_node *a, t_stack_node *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (b)
	{
		b->push_cost = b->current_index;
		if (!(b->above_median))
			b->push_cost = b_len - (b->current_index);
		if (b->target_node->above_median)
			b->push_cost += b->target_node->current_index;
		else
			b->push_cost += a_len - (b->target_node->current_index);
		b = b->next;
	}
}

void	find_cheapest(t_stack_node *b)
{
	t_stack_node	*cheapest_node;
	long			price;

	price = LONG_MAX;
	if (!b)
		return ;
	while (b)
	{
		if (b->push_cost < price)
		{
			cheapest_node = b;
			price = b->push_cost;
		}
		b = b->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	target_node(a, b);
	push_price(a, b);
	find_cheapest(b);
}

//int main()
//{
//	t_stack_node *a;
//
//	a = NULL;
//	a = malloc(sizeof(t_stack_node));
//	a->val = 1;
//	a->prev = NULL;
//	a->next =  malloc(sizeof(t_stack_node));;
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
//	//current_index(a);
//
//	t_stack_node *b = malloc(sizeof(t_stack_node));
//	b->val = 0;
//	b->prev = NULL;
//
//	b->next = malloc(sizeof(t_stack_node));
//	b->next->val = 100;
//	b->next->next = NULL;
//
//	current_index(a);
//	current_index(b);
//	target_node(a, b);
//	push_price(a, b);
//	find_cheapest(b);
//
//
//	printf("Before sort: ");
//	printf("a-> val %d\n", a->val);
//	printf("a->next -> val %d\n", a->next->val);
//	printf("a->next->next -> val %d\n", a->next->next->val);
//
//	//sort_three(&a);
//
//	printf("After sort: ");
//	printf("a-> val %d\n", a->val);
//	printf("a->next -> val %d\n", a->next->val);
//	printf("a->next->next -> val %d\n", a->next->next->val);
//
//	free(a);
//}