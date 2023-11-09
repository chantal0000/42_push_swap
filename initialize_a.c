/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:55:03 by chbuerge          #+#    #+#             */
/*   Updated: 2023/11/09 10:08:08 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// atoi
#include <stdlib.h>
// write
#include <unistd.h>
// printf
#include <stdio.h>
#include <string.h>
#include "push_swap.h"
//____________________test__________________________
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int	value;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;
#endif
//____________________________________________________

// creating a new node
t_stack *create_node(int value)
{
	t_stack *new_node = malloc(sizeof (t_stack));
	if (!new_node)
		return ;
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
		return;
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
}



/*
void	initialize_a(t_stack **a, char **arg)
{

}*/
