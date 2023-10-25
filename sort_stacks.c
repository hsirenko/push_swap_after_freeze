/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 01:12:54 by hsirenko          #+#    #+#             */
/*   Updated: 2023/09/18 18:38:23 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b,
				t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
				t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	fin_rot(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	fin_rot(b, cheapest_node, 'b');
	fin_rot(a, cheapest_node->target_node, 'a');
	pa(a, b, false);
}

void	stack_sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;

	if (stack_len(*a) == 5)
		sort_five(a, b);
	else
	{
		while (stack_len(*a) > 3)
			pb(b, a, false);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	current_index(*a);
	smallest = find_smallest(*a);
	while (*a != smallest)
	{
		if (smallest->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

//	t_stack_node *current;
//
//	current = *a;
//	while (current)
//	{
//		printf("debug a: %d \n", current->val);
//		current = current->next;
//	}
//	current = *b;
//	while (current)
//	{
//		printf(" debug b: %d \n", current->val);
//		current = current->next;
//	}

//void	stack_sort(t_stack_node **a, t_stack_node **b)
//{
//	int len_a;
//	t_stack_node *smallest;
//
//	if (!*a || !*b)
//		return;
//	len_a = stack_len(*a);
//
//	if (len_a-- > 3 && !stack_sorted(*a))
//		pb(b, a, false);
//	if (len_a-- > 3 && !stack_sorted(*a))
//		pb(b, a, false);
//	while (len_a-- > 3 && !stack_sorted(*a))
//	{
//		init_nodes(*a, *b);
//		move_nodes(a, b);
//	}
//	sort_three(a);
//	while (*b)
//	{
//		init_nodes(*a, *b);
//		move_nodes(a, b);
//	}
//	current_index(*a);
//	smallest = find_smallest(*a);
//	if (smallest->above_median) {
//		while (*a != smallest)
//			ra(a, false);
//	} else {
//		while (*a != smallest)
//			rra(a, false);
//	}
//}

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
//	a->next->next->next->next->next = malloc(sizeof(t_stack_node));
//	a->next->next->next->next->next->val = 77;
//	a->next->next->next->next->next->prev = a->next->next->next->next;
//	a->next->next->next->next->next->next = NULL;
//
//	//current_index(a);
//
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
//	printf("Before sort: \n");
//	printf("a1->val %d\n", a->val);
//	printf("a2->val %d\n", a->next->val);
//	printf("a3->val %d\n", a->next->next->val);
//	printf("a4->val %d\n", a->next->next->next->val);
//	printf("a5->val %d\n", a->next->next->next->next->val);
//	printf("a6->val %d\n", a->next->next->next->next->next->val);
//
//	//sort_five(&a, &b);
//	//stack_sorted(a);
//	stack_sort(&a, &b);
//	//init_nodes(a, b);
//	//move_nodes(&a, &b);
//
//	printf("After sort:\n ");
//	printf("a1->val %d\n", a->val);
//	printf("a2->val %d\n", a->next->val);
//	printf("a3->val %d\n", a->next->next->val);
//	printf("a4->val %d\n", a->next->next->next->val);
//	printf("a5->val %d\n", a->next->next->next->next->val);
//	printf("a6->val %d\n", a->next->next->next->next->next->val);
//
//	free(a);
//	free(b);
//}

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
//	//current_index(a);
//
//	t_stack_node *b = malloc(sizeof(t_stack_node));
//	b->val = 0;
//	b->prev = NULL;
//
//	b->next = malloc(sizeof(t_stack_node));
//	b->next->val = 100;
//	b->next->prev = b;
//	//b->next->next = NULL;
//
//	b->next->next = malloc(sizeof(t_stack_node));
//	b->next->next->val = 1000;
//	b->next->next->prev = b->next;
//	b->next->next->next = NULL;
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
//	printf("a-> val %d\n", a->val);
//	printf("a->next -> val %d\n", a->next->val);
//	printf("a->next->next -> val %d\n", a->next->next->val);
//
//	//sort_three(&a);
//	stack_sort(&a, &b);
//	//move_nodes(&a, &b);
//
//	printf("After sort: ");
//	printf("a-> val %d\n", b->val);
//	printf("a->next -> val %d\n", b->next->val);
//	printf("a->next->next -> val %d\n", b->next->next->val);
//
//	free(a);
//	free(b);
//}