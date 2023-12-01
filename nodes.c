/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:55:03 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/01 12:09:55 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



// function that finds the last node in my list
t_stack	*last_node(t_stack *head)
{
	if (!head)
		return (NULL);
	while(head->next != NULL)
		head = head->next;
	return (head);
}


// need a function to find the smallest and biggest node
t_stack	*largest_element(t_stack *head)
{
	long	max;
	t_stack *largest_node;

	if (!head)
		return (NULL);
	max = INT_MIN;
	while(head)
	{
		// if the value in node is bigger than max
		if (max < head->value)
		{
			// make it the new max
			max = head->value;
			largest_node = head;
		}
		// move to next node
		head = head->next;
	}
	return (largest_node);
}

t_stack	*smallest_element(t_stack *head)
{
	int min;
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
	// loop until the end of the stack (until stack == NULL)
	while (stack)
	{
		// traversing through the elements, moving to the next node in the list
		stack = stack->next;
		i++;
	}
	return (i);
}


// creating a new node
t_stack *create_node(int value)
{
	t_stack *new_node = malloc(sizeof (t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

// insert at the end of the list
void insert_end(t_stack **head, int value)
{
	t_stack *new_node = create_node(value);
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	t_stack *temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->prev = temp;
}

// display doubly linked list
void display(t_stack *head)
{
	t_stack *current = head;
	while(current!= NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}



/*
int main(int argc, char **argv)
{
	t_stack *head = NULL;
	int i;
	int value;

	i = 1;
	value = 0;
	while(i < argc)
	{
		value = atoi(argv[i]);
		insert_end(&head, value);
		i++;
	}
	display(head);
	return (0);
}*/



/*
void	initialize_a(t_stack **a, char **arg)
{

}*/
