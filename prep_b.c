/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:54:06 by chbuerge          #+#    #+#             */
/*   Updated: 2023/11/24 12:22:26 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find the target node, a function that finds the smallest biggr
// node in stack a for every element in stack b, if there is none
// the target node is the smallest node
void	find_target_node_for_b(t_stack *a, t_stack *b)
{
	// traverse/ durchqueren stack a
	t_stack	*current_a;
	// keep track of the node in a that is best match for the current node in b
	t_stack	*target_node;
	// var to store the index of best match found in stack
	long	best_match_index;
	// iterate through each node in stack b
	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		// wir gehen durch a nodes
		while (current_a)
		{
			// falls das value von a groesser ist als value von b
			// UND value von a kleiner ist als best_match_index (LONG MAX)
			if (current_a->value > b->value && current_a->value < best_match_index)
			{
				// wir haben ein match gefunden
				best_match_index = current_a->value;
				// node in a wird target node
				target_node = current_a;
			}
			// wir gehen zum naechsten node um zu sehen ob es besser passt
			current_a = current_a->next;
		}
		// wir haben kein match gefunden? heisst es gibt kein bigger node,
		// dann ist das kleinste node ein match
		if (LONG_MAX == best_match_index)
			b->target_node = smallest_element(a);
		else
			// wir haben match, b target node ist die gefundene target node
			b->target_node = target_node;
		// wir suchen target node fuer den nachsten node in b
		b = b->next;
	}
}

void	set_data_b(t_stack *a, t_stack *b)
{
	node_index(a);
	node_index(b);
	find_target_node_for_b(a, b);
}
