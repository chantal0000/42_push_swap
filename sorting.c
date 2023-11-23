/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:41:51 by chbuerge          #+#    #+#             */
/*   Updated: 2023/11/23 11:22:12 by chbuerge         ###   ########.fr       */
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
		set_data(*a, *b);
		// move a to b...
	}
	sort_three(a);
	while (*b)
	{
		// code here...
	}
	// ...
	// move smallest to the top of a (final)
}
// function to index nodes within a stack and catogarizes them in terms of
// above or below median
void	node_index(t_stack *stack)
{
	// int i to store the index of current node
	int	i;
	// int median to store the pos of median in stack
	int	median;

	i = 0;
	// check if stack is empty
	if (!stack)
		return (NULL);
	// median is the length of the stack / 2
	median = stack_len(stack) / 2;
	// loop through the stack
	while (stack)
	{
		// index of the first node is i
		stack->i = i;
		// check if index is smaller or equal to median
		if (i <= median)
			// if yes above_median is true
			stack->above_median = true;
		else
			// above_median is false
			stack->above_median = false;
		// check the next node of the stack
			stack = stack->next;
		// ++i, why not i++??
		++i;
	}
}
//

// find the target node, a function that finds the smallest biggr
// node in stack a for every element in stack b, if there is none
// the target node is the smallest node
void	find_target_node(t_stack *a, t_stack *b)
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

// median oder zentralwert -> der Wert der genau in der Mitte einer
// Datenverteilung liegt

// cost analyse function, calculates the cost of each push, the sum of
// the amount of operations it would take to put the target node and b on top
void	operation_cost(t_stack *a, t_stack *b)
{
	// int for length of a and b
	int	a_len;
	int	b_len;
	// fill len
	a_len = stack_len(a);
	b_len = stack_len(b);
	// loop through b
	while (b)
	{
		// b price is = b index
		b->operations_cost = b->i;
		// if b above median is false
		if (!(b->above_median))
			// b price is = leb_b - index of b
			b->operations_cost = b_len - b->i;
		// if b target node is above median
		if (b->target_node->above_median)
			// b price = b price + b->target_node->currennt_position
			b->operations_cost = b->operations_cost + b->target_node->i;
		// else meaning b is above median and its target node in a is below median
		else
			// price b = price b + len_a - (b->target?node->current_position)
			b->operations_cost = b->operations_cost - (b->target_node->i);
		b = b->next;
	}
}
// ????
void	find_cheapest(t_stack *b)
{
	long	best_match_value;
	// to store the node with the cheapest push price
	t_stack	*best_match_node;

	if (!b)
		return (NULL);
	best_match_value = LONG_MAX;
	while (b)
	{
		//if bs operation costs are lower than best_match value
		if (b->operations_cost < best_match_value)
		{
			// update best match value to bs costs
			best_match_value = b->operations_cost;
			// FOUND NEW cheapest, set it to best_match
			best_match_node = b;
		}
		// move on to the next node
		b = b->next;
	}
	// set cheapest of the best_match_node to true
	best_match_node->cheapest = true;
}


void	set_data(t_stack *a, t_stack *b)
{
	node_index(a);
	node_index(b);
	find_target_node(a, b);
	operation_cost(a, b);
	find_cheapest(b);
}




// checked in main.c
// check if == 2
	// swap numbers
// check if 3
	// sort_three
// else
	// sort, implement Turk Algorithm
