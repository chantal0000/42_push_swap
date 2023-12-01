/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:39:23 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/01 12:33:53 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function that rotates the top node of a and b to its bottom if its the cheapest
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	node_index(*a);
	node_index(*b);
}

void reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	node_index(*a);
	node_index(*b);
}
void	move_to_top(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}



// move cheapest node from a to b until there is only 3 left in a
void	prepare_and_push_cheapest_a_to_b(t_stack **a, t_stack **b)
{
	//write(1, "prepare_and_push_cheapest_a_to_b\n", 50);
	// t_stack to track cheapest node
	t_stack	*cheapest_node;
	// cheapest node is function get_chepeast(*a)
	cheapest_node = get_cheapest(*a);
	//printf("cheapest node: %d\n", cheapest_node->value);
	//printf("target_node of cheapest node: %d\n", cheapest_node->target_node->value);
	//display(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
	{// rotate_both(a, b, cheapest node)
		rotate_both(a, b, cheapest_node);
	}
	// else if cheapest is not above med && and target node is also below
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		//rev rotate rotate_both
		reverse_rotate_both(a, b, cheapest_node);
	// move to top (prep for push( a, cheapest node, a))
	move_to_top(a, cheapest_node, 'a');
	// "" b, cheapest_node->targetnode, 'b'
	move_to_top(b, cheapest_node->target_node, 'b');
	// final push
	pb(a, b);
}
t_stack	*get_cheapest(t_stack *stack)
{
	//write(1, "get_cheapest\n", 20);
	if (!stack)
	{
		return (NULL);
	}
	while (stack)
	{
		if (stack->cheapest)
				return (stack);
		stack = stack->next;
	}
	return (NULL);
}
