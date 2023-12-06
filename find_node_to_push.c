/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_node_to_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:47:46 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/06 09:48:24 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
