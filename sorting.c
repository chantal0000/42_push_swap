/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:41:51 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/06 09:49:13 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// starts the sorting of the stack depending on the size of stack
void	start_sort(t_stack	**a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	if (len == 2)
		sa(a);
	else if (len == 3)
		sort_three(a);
	else
		sort_stacks(a, b);
}

// 1. push two numbers from top of a to b without checking anything
// 2. calculate how many operations would be needed to put
	// it in correct position for all and then decide on the cheapest one
// 3. last three elements can be sortet within a (max 2 operations)
// 4. we push everyhing back, we check if it is ushed to the correct pos.
	// otherwise we rotate the stack
// 5. last step bring min number to the top of the stack a,
	// check if everything is sorted
// len_a-- post decrementation, checks first then decrements
void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3)
		pb(b, a);
	if (len_a-- > 3)
		pb(b, a);
	while (len_a-- > 3)
	{
		set_data_a(*a, *b);
		prepare_and_push_cheapest_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		set_data_b(*a, *b);
		move_b_to_a(a, b);
	}
	min_on_top(a);
}

// filling the nodes with all necesssary information
void	set_data_a(t_stack *a, t_stack *b)
{
	node_index(a);
	node_index(b);
	find_target_node_for_a(a, b);
	operation_cost(a, b);
	find_cheapest(a);
}
