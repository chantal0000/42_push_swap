/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:58:42 by chbuerge          #+#    #+#             */
/*   Updated: 2023/11/20 10:07:41 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// a function that pushes a top node from one stack on top of another stack
// not a and b but source dest because it can push in either direction
void push(t_stack **source, t_stack **destination)
{
// define the node to be pushed
	t_stack *node_to_be_pushed;
// check if the src stack exists
	if (!*source)
		return;
// assign node to be pushed to *source meaning the top node of the source list
		node_to_be_pushed = *source;
// make the second node in the src list the new top node
		*source = (*source)->next;
// check if the neew *src exists and if it does make it point to NULL to make it first
		if (*source)
			(*source)->prev = NULL;
// make the node to be pushed prev to NULL to detach it from the list
		node_to_be_pushed->prev = NULL;
// check if dest exists
		if (!*destination)
		{
// if not dest is equal to node to be pushed
			*destination = node_to_be_pushed;
			// node to be pushed next is also NULL
			node_to_be_pushed->next = NULL;
		}
// if not empty:
// node to be pushed next is *destination cause its the top node of the dst list
	node_to_be_pushed->next = *destination;
// make old top node prev point to new top node
	(*destination)->prev = node_to_be_pushed;
// make the node to be pushed the new *dst
	*destination = node_to_be_pushed;
}
