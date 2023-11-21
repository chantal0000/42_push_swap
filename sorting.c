/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:41:51 by chbuerge          #+#    #+#             */
/*   Updated: 2023/11/21 19:33:45 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. push two numbers from top of a to b without checking anything
// 2. calculate how many operations would be needed to put it in correct position
//	for all and then decide on the cheapest one
// 3. last three elements can be sortet within a (max 2 operations)
// 4. we push everyhing back, we check if it is ushed to the correct pos. otherwise
	// we rotate the stack
// 5. last step bring min number to the top of the stack a, check if everything is sorted


void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	// if a is > 3 push one element to be
	if (len_a - 1 > 3 && is_sorted(*a) == 1)
		pb(b, a);
	// else if (if a is still bigger) push another one
	if (len_a - 1 > 3 && is_sorted(*a) == 1)
		pb(b, a);
	while (len_a - 1 > 3 && is_sorted(*a) == 1)
	{
		// code here...
	}
	sort_three(a);
	while (*b)
	{
		// code here...
	}
	// ...
	// move smallest to the top of a (final)
}

// find the target node, a function that finds the smallest biggr
// node in stack a for every element in stack b, if there is none
// the target node is the smallest node
void	find_target_node(t_stack *a, t_stack *b)
{
	// traverse stack a
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








// checked in main.c
// check if == 2
	// swap numbers
// check if 3
	// sort_three
// else
	// sort, implement Turk Algorithm
