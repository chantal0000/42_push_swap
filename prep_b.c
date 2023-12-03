/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:54:06 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/03 13:35:27 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find the target node, a function that finds the smallest biggr
// node in stack a for every element in stack b, if there is none
// the target node is the smallest node
// traverse/ durchqueren stack a
// keep track of the node in a that is best match for the current node in b
// var to store the index of best match found in stack
// iterate through each node in stack b
// wir gehen durch a nodes
// falls das value von a groesser ist als value von b
// UND value von a kleiner ist als best_match_index (LONG MAX)
// wir haben ein match gefunden
// node in a wird target node
// wir gehen zum naechsten node um zu sehen ob es besser passt
// wir haben kein match gefunden? heisst es gibt kein bigger node,
// dann ist das kleinste node ein match
// wir haben match, b target node ist die gefundene target node
// wir suchen target node fuer den nachsten node in b
void	find_target_node_for_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_node = smallest_element(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_data_b(t_stack *a, t_stack *b)
{
	node_index(a);
	node_index(b);
	find_target_node_for_b(a, b);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node);
	pa(a, b);
}

void	min_on_top(t_stack **a)
{
	while ((*a)->value != smallest_element(*a)->value)
	{
		if (smallest_element(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	prep_for_push(t_stack **stack, t_stack *top_node)
{
	while (*stack != top_node)
	{
		if (top_node->above_median)
			ra(stack);
		else if (!top_node->above_median)
			rra(stack);
	}
}
