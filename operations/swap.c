/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:51:39 by chbuerge          #+#    #+#             */
/*   Updated: 2023/11/17 16:30:32 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. swap - swap the first element with the second element of a stack
	// sa, sb, ss (swap of two stacks)
/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
*/
// use the other two operations to solve this? --> FREDDY
//static void?
void	swap(t_stack **head)
{
	// check if the stack is empty or if there's only one node in the stack
	if(!*head || !(*head)->next)
		return;
	// update *head to point to the second node in the stack
	// making the second node the first node
	*head = (*head)->next;
	// make the prev pointer of the former top node point to the new top node
	(*head)->prev->prev = *head;
	// updates the next pointer of the node before the new top node
	// to skip the old top node and point directly to the new top node
	(*head)->prev->next = (*head)->next;
	// check if there is a node after the new top node
	if ((*head)->next)
		// updates prev pointer back to the top
		(*head)->next->prev = (*head)->prev;
	// next pointer of new top node points to old top node
	(*head)->next = (*head)->prev;
	// prev pointer of new top node to NULL
	(*head)->prev = NULL;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
// 2. take an element from one stack and put it at the top of another stack
	// pa, pb,

/*
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
*/
// 3. rotate - move/shift up all elements of the stack by 1
	// ra, rb, rr (both)
/*
void	rotate(t_stack **stack)
{
	t_stack *head = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (head->next != NULL)
	{
		head = head->next;
	}
	head->next = *stack;
	(*stack)->prev = head;
	*stack = (*stack)->next;
// freddi added to close
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

*/

/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
*/
// 4. reverse rotate - move/shift all elements one down
	// rra, rrb, rrr
/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.*/
