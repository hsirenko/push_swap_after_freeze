/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:06:22 by helensirenk       #+#    #+#             */
/*   Updated: 2023/06/29 22:03:08 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./printf/ft_printf.h"
# include "./libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					val;
	int					current_index;
	int					push_cost;
	bool				cheapest;
	bool				above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// error handlers
void				free_2d_array(char **argv);
void				free_stack(t_stack_node **stack);
int					error_repetition(t_stack_node *a, int nb);
void				error_free(t_stack_node **a, char **argv, bool argc_2);
int					error_syntax(char *str);
// init stack a
long				ft_atol(const char *str);
void				init_stack_a(t_stack_node **a, char **argv, bool argc_2);
void				current_index(t_stack_node *stack);
void				push_price(t_stack_node *a, t_stack_node *b);
void				find_cheapest(t_stack_node *b);
void				init_nodes(t_stack_node *a, t_stack_node *b);
// sort stacks
void				fin_rot(t_stack_node **stack, t_stack_node *top_node,
						char stack_name);
void				stack_sort(t_stack_node **a, t_stack_node **b);
void				sort_three(t_stack_node **a);
void				sort_five(t_stack_node **a, t_stack_node **b);
bool				stack_sorted(t_stack_node *stack);
// stack utils
t_stack_node		*find_last_node(t_stack_node *head);
void				append_node(t_stack_node **stack, int nb);
int					stack_len(t_stack_node *stack);
t_stack_node		*find_smallest(t_stack_node *stack);
t_stack_node		*return_cheapest(t_stack_node *stack);
char				*ft_strcpy(char *s1, char *s2, int n);
char				**f_split(char *str, char space);

// push_swap.c
void				several_digits(char arr[], int size);
void				single_char_list(char **arr, int size);
void				max_min(char arr_num[], int size);

// operations
void				sa(t_stack_node **a, bool check);
void				sb(t_stack_node **b, bool check);
void				ss(t_stack_node **a, t_stack_node **b, bool check);
void				pa(t_stack_node **a, t_stack_node **b, bool check);
void				pb(t_stack_node **b, t_stack_node **a, bool check);
void				ra(t_stack_node **a, bool check);
void				rb(t_stack_node **b, bool check);
void				rr(t_stack_node **a, t_stack_node **b, bool check);
void				rra(t_stack_node **a, bool check);
void				rrb(t_stack_node **b, bool check);
void				rrr(t_stack_node **a, t_stack_node **b, bool check);

#endif