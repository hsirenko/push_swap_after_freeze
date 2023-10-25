/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 01:12:54 by hsirenko          #+#    #+#             */
/*   Updated: 2023/09/18 18:38:23 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **a)
{
	t_stack_node	*last_node;
	int				len;

	len = stack_len(*a);
	if (NULL == *a || NULL == a || len == 1)
		return ;
	last_node = find_last_node(*a);
	last_node->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool check)
{
	rotate(a);
	if (!check)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool check)
{
	rotate(b);
	if (!check)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool check)
{
	rotate(a);
	rotate(b);
	if (!check)
		ft_printf("rr\n");
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
//	printf("Before rotate: ");
//	printf("a-> val %d\n", a->val);
//	printf("a->next -> val %d\n", a->next->val);
//
//	ra(&a, false);
//
//	printf("After rotate: ");
//	printf("a-> val %d\n", a->val);
//	printf("a->next -> val %d\n", a->next->val);
//
//	free(a);
//	free(b);
//}