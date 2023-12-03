/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:58:42 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/03 14:07:40 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// a function that pushes a top node from one stack on top of another stack
// not a and b but source dest because it can push in either direction

// define the node to be pushed
// check if the src stack exists
// assign node to be pushed to *source meaning the top node of the source list
// make the second node in the src list the new top node
// check if the new *src exists and if it does make it point to NULL
	//to make it first
// make the node to be pushed prev to NULL to detach it from the list
// check if dest exists
// if not dest is equal to node to be pushed
		// node to be pushed next is also NULL
// if not empty:
// node to be pushed next is *destination cause its the top node of the dst list
// make old top node prev point to new top node
// make the node to be pushed the new *dst
void	push(t_stack **destination, t_stack **source)
{
	t_stack	*node_to_be_pushed;

	if (!*source)
		return ;
	node_to_be_pushed = *source;
	*source = (*source)->next;
	if (*source)
		(*source)->prev = NULL;
	node_to_be_pushed->prev = NULL;
	if (!*destination)
	{
		*destination = node_to_be_pushed;
		node_to_be_pushed->next = NULL;
	}
	else
	{
		node_to_be_pushed->next = *destination;
		(*destination)->prev = node_to_be_pushed;
	}
	*destination = node_to_be_pushed;
}

// pa - push the first element of b and put it on top of a
void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

// pb - push the first element of a and put it at the top of b
void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
