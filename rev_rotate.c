/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 01:12:54 by hsirenko          #+#    #+#             */
/*   Updated: 2023/09/18 18:38:23 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack_node **a)
{
	t_stack_node	*last_node;
	int				len;

	len = stack_len(*a);
	if (NULL == *a || NULL == a || len == 1)
		return ;
	last_node = find_last_node(*a);
	last_node->prev->next = NULL;
	last_node->next = *a;
	last_node->prev = NULL;
	*a = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a, bool check)
{
	rev_rotate(a);
	if (!check)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool check)
{
	rev_rotate(b);
	if (!check)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool check)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!check)
		ft_printf("rrr\n");
}

//int main()
//{
//	t_stack_node *a;
//
//	a = NULL;
//	a = malloc(sizeof(t_stack_node));
//	a->val = 42;
//	a->prev = NULL;
//
//	a->next =  malloc(sizeof(t_stack_node));;
//	a->next->val = 123;
//	a->next->prev = a;
//	a->next->next = NULL;
//
//	t_stack_node *b;
//
//	b = NULL;
//	b = malloc(sizeof(t_stack_node));
//	b->val = 0;
//	b->prev = NULL;
//
//	b->next = malloc(sizeof(t_stack_node));
//	b->next->val = 100;
//	b->next->prev = b;
//	b->next->next = NULL;
//
//	printf("Before rotate: ");
//	printf("b-> val %d\n", b->val);
//	printf("b->next -> val %d\n", b->next->val);
//
//	rrb(&b, false);
//
//	printf("After rotate: ");
//	printf("b-> val %d\n", b->val);
//	printf("b->next -> val %d\n", b->next->val);
//
//	free(a);
//	free(b);
//}