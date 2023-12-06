/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:41:51 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/06 09:30:00 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. push two numbers from top of a to b without checking anything
// 2. calculate how many operations would be needed to put
	// it in correct position for all and then decide on the cheapest one
// 3. last three elements can be sortet within a (max 2 operations)
// 4. we push everyhing back, we check if it is ushed to the correct pos.
	// otherwise we rotate the stack
// 5. last step bring min number to the top of the stack a,
	// check if everything is sorted
// len_a-- post decrementation, checks first then decrements

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

// function to index nodes within a stack and catogarizes them in terms of
// above or below median
// median is the length of the stack / 2
// ++i
void	node_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->i = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

// a function to find target nodes in stack b for every element in stack a
// biggest smallest, if there is none than biggest node
void	find_target_node_for_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (LONG_MIN == best_match_index)
			a->target_node = largest_element(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

// median oder zentralwert -> der Wert der genau in der Mitte einer
// Datenverteilung liegt
// cost analyse function, calculates the cost of each push, the sum of
// the amount of operations it would take to put the target node and b on top
	// b price is = b index
	// if b above median is false
	// b price is = leb_b - index of b
	// if b target node is above median
	// b price = b price + b->target_node->currennt_position
	// else meaning b is above median and its target node in a is below median
	// price b = price b + len_a - (b->target?node->current_position)
void	operation_cost(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (a)
	{
		a->operations_cost = a->i;
		if (!(a->above_median))
			a->operations_cost = a_len - a->i;
		if (a->target_node->above_median)
			a->operations_cost = a->operations_cost + a->target_node->i;
		else
			a->operations_cost = a->operations_cost - (a->target_node->i);
		a = a->next;
	}
}
		//if bs operation costs are lower than best_match value
		// update best match value to bs costs
		// FOUND NEW cheapest, set it to best_match
			// set cheapest of the best_match_node to true

void	find_cheapest(t_stack *stack)
{
	long	best_match_value;
	t_stack	*best_match_node;

	if (!stack)
		return ;
	best_match_value = LONG_MAX;
	while (stack)
	{
		if (stack->operations_cost < best_match_value)
		{
			best_match_value = stack->operations_cost;
			best_match_node = stack;
		}
		stack = stack->next;
	}
	best_match_node->cheapest = true;
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
