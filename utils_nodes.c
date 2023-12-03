/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:27:30 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/03 13:27:56 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function that finds the last node in my list
t_stack	*last_node(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

// need a function to find the smallest and biggest node
t_stack	*largest_element(t_stack *head)
{
	long	max;
	t_stack	*largest_node;

	if (!head)
		return (NULL);
	max = INT_MIN;
	while (head)
	{
		if (max < head->value)
		{
			max = head->value;
			largest_node = head;
		}
		head = head->next;
	}
	return (largest_node);
}

t_stack	*smallest_element(t_stack *head)
{
	int		min;
	t_stack	*smallest_node;

	if (!head)
		return (NULL);
	min = INT_MAX;
	while (head)
	{
		if (min > head->value)
		{
			min = head->value;
			smallest_node = head;
		}
		head = head->next;
	}
	return (smallest_node);
}

// calculate and return the length of my stack
// stack is a pointer to the first node of the linked list
int	stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
