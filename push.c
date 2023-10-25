/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 01:12:54 by hsirenko          #+#    #+#             */
/*   Updated: 2023/09/18 18:38:23 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*push_node;

	if (NULL == *a)
		return ;
	push_node = *a;
	*a = (*a)->next;
	if (*a)
	{
		(*a)->prev = NULL;
		push_node->prev = NULL;
	}
	if (NULL == *b)
	{
		*b = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *b;
		push_node->next->prev = push_node;
		*b = push_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool check)
{
	push(a, b);
	if (!check)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool check)
{
	push(b, a);
	if (!check)
		ft_printf("pb\n");
}

//int main()
//{
//	t_stack_node *a;
//
//	a = NULL;
//	a = malloc(sizeof(t_stack_node));
//	a->val = 42;
//	a->prev = NULL;
//	a->next =  malloc(sizeof(t_stack_node));;
//	a->next->val = 123;
//	a->next->prev = a;
//	a->next->next = NULL;
//
//	t_stack_node *b = malloc(sizeof(t_stack_node));
//	b->val = 0;
//	b->prev = NULL;
//
//	b->next = malloc(sizeof(t_stack_node));
//	b->next->val = 100;
//	b->next->next = NULL;
//
//	printf("Before push: ");
//	printf("a-> val %d\n", a->val);
//	printf("b -> val %d\n", b->val);
//
//	pb(&b, &a, false);
//
//	printf("After push: ");
//	printf("b -> val %d\n", b->val);
//	printf("a -> val %d\n", a->val);
//
//	free(a);
//	free(b);
//}