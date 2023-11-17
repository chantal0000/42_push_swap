/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:44:49 by chbuerge          #+#    #+#             */
/*   Updated: 2023/11/17 19:39:45 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// is actually reverse_rotate? NOOOOOOO???!
void	rotate(t_stack **head)
{
	t_stack	*final_node;
	//find the last node in the list
	final_node = last_node(*head);
	// the next node after final_node should be the current top one
	final_node->next = *head;
	//update top node to be the next node in the list (former second node)
	*head = (*head)->next;
	// the next node after the original final_node is now the old top node
	// therefore the next pointer points to NULL
	final_node->next->next = NULL;
	// the new top nodes prev pointer points now to NULL
	(*head)->prev = NULL;
	printf("final_node: %d\n", final_node->value);
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

