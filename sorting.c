/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:41:51 by chbuerge          #+#    #+#             */
/*   Updated: 2023/11/28 18:25:31 by chbuerge         ###   ########.fr       */
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

///// CHECK IF SORTED11111111
// ?????????? while (b)...
void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	// if a is > 3 push one element to be
	if (len_a-- > 3 )
		pb(a, b);
	// else if (if a is still bigger) push another one
	if (len_a-- > 3 )
		pb(a, b);
	while (len_a-- > 3)
	{
		set_data_a(*a, *b);
		// issues in this function
		prepare_and_push_cheapest_a_to_b(a, b);
	}
	//display(*b);
	//sort_three(a);
	//printf("sort_stacks function is running\n");
	//while (*b)
	//{
		// code here...
	//}*/
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
		return ;
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
// a function to find target nodes in stack b for every element in stack a
// biggest smallest, if there is none than biggest node
void	find_target_node_for_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	while(a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value && current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (LONG_MIN == best_match_index)
		{
			a->target_node = largest_element(b);
			//printf("target node1: %d\n", a->target_node->value);
		}
		else
		{
			a->target_node = target_node;
			//printf("target node2: %d\n", a->target_node->value);
		}
		a = a->next;
	}
}


// median oder zentralwert -> der Wert der genau in der Mitte einer
// Datenverteilung liegt

// cost analyse function, calculates the cost of each push, the sum of
// the amount of operations it would take to put the target node and b on top
void	operation_cost(t_stack *a, t_stack *b)
{
	//write(1, "operation_cost\n", 15);
	// int for length of a and b
	int	a_len;
	int	b_len;
	// fill len
	a_len = stack_len(a);
	b_len = stack_len(b);

	// loop through b
	while (a)
	{
		// b price is = b index
		a->operations_cost = a->i;
		// if b above median is false
		if (!(a->above_median))
		{
			// b price is = leb_b - index of b
			a->operations_cost = a_len - a->i;
		}
		// if b target node is above median
		if (a->target_node->above_median)
		{// b price = b price + b->target_node->currennt_position
			a->operations_cost = a->operations_cost + a->target_node->i;
		}
		// else meaning b is above median and its target node in a is below median
		else
		{
			// price b = price b + len_a - (b->target?node->current_position)
			a->operations_cost = a->operations_cost - (a->target_node->i);
		}
		a = a->next;
	}
}
// ????
void	find_cheapest(t_stack *stack)
{
	long	best_match_value;
	// to store the node with the cheapest push price
	t_stack	*best_match_node;

	if (!stack)
	{
		return ;
	}
	best_match_value = LONG_MAX;
	while (stack)
	{
		//if bs operation costs are lower than best_match value
		if (stack->operations_cost < best_match_value)
		{
			// update best match value to bs costs
			best_match_value = stack->operations_cost;
			// FOUND NEW cheapest, set it to best_match
			best_match_node = stack;
		}
		// move on to the next node
		stack = stack->next;
	}
	// set cheapest of the best_match_node to true
	best_match_node->cheapest = true;
	//printf("operation costs %d\n", best_match_node->operations_cost);
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
