/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 01:12:54 by hsirenko          #+#    #+#             */
/*   Updated: 2023/09/18 18:38:23 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **a)
{
	int	len;

	len = stack_len(*a);
	if (NULL == *a || NULL == a || len == 1)
		return ;
	*a = (*a)->next;
	(*a)->prev->prev = *a;
	(*a)->prev->next = (*a)->next;
	if ((*a)->next)
	{
		(*a)->next->prev = (*a)->prev;
	}
	(*a)->next = (*a)->prev;
	(*a)->prev = NULL;
}

void	sa(t_stack_node **a, bool check)
{
	swap(a);
	if (!check)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool check)
{
	swap(b);
	if (!check)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool check)
{
	swap(a);
	swap(b);
	if (!check)
		ft_printf("ss\n");
}

//int main()
//{
////	t_stack_node *a;
////
////	a = NULL;
////	a = malloc(sizeof(t_stack_node));
////	a->val = 42;
////	a->prev = NULL;
////
////	a->next =  malloc(sizeof(t_stack_node));;
////	a->next->val = 123;
////	a->next->prev = a;
////	a->next->next = NULL;
//
//
//	t_stack_node *b;
//
//	b = NULL;
//	b = malloc(sizeof(t_stack_node));
//	b->val = 10;
//	b->prev = NULL;
//
//	b->next = malloc(sizeof(t_stack_node));
//	b->next->val = 20;
//	b->next->prev = b;
//	b->next->next = NULL;
//
//	b->next->next= malloc(sizeof(t_stack_node));
//	b->next->next->val = 100;
//	b->next->next->prev = b->next;
//	b->next->next->next = NULL;
//
//
////	b->next = malloc(sizeof(t_stack_node));
////	b->next->val = 100;
////	b->next->prev = b;
////	b->next->next = 0;
//
//
////	b->next->next = malloc(sizeof(t_stack_node));
////	b->next->next->val = -998;
////	b->next->next->prev = b->next;
////	b->next->next->next = NULL;
//
//	printf("Before swap: ");
//	printf("b-> val %d\n", b->val);
//	printf("b->next -> val %d\n", b->next->val);
//	printf("third element %d\n", b->next->next->val);
//
////	sb(&b, false);
//	// swap2(b1, b2);
//	//swap2(b0, b1);
//	sb(&b, false);
//
////	[b, b->next]
////	[b->next, b]
//
//
////	[10, 20, 100]
////	[20, 10, 100]
//	printf("After swap: ");
////	printf("first element %d\n", b->next->val);
//	printf("first element %d\n", b->val);
//	printf("second element %d\n", b->next->val);
//	printf("third element %d\n", b->next->next->val);
////	printf("second element %d\n", b->val);
//
////	[b, b1]
////	[b1, b]
////	printf("b->next -> val %d\n", b->next->val);
////	printf("b->next->next -> val %d\n", b->next->next->val);
//
//	//free(a);
//	free(b);
//}

//static void swap3( t_stack_node* node1, t_stack_node* node2 )
//{
//	int tmp = node1->val;
//	node1->val = node2->val;
//	node2->val = tmp;
//
//}

//static void swap2( t_stack_node* node1, t_stack_node* node2 )
//{
//	if (node1 == 0)
//		return;
//	if (node2 == 0)
//		return;
//
//	if (node1->prev)
//		node1->prev->next = node2;
//
//	if (node2->next)
//	{
//		printf("node2->next->val %d\n",node2->next->val );
//		node1->next = node2->next;
//	}
//
//	node2->next = node1;
//	node1->prev = node2;
//}