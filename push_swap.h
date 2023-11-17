/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:05:03 by chbuerge          #+#    #+#             */
/*   Updated: 2023/11/17 19:42:44 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
// write
#include <unistd.h>
 // printf
#include <stdio.h>
 // atoi, exit
#include <stdlib.h>
// strcmp
#include <string.h>
// int max and min
#include <limits.h>
// libft
#include "./libft/libft.h"

// s_ for struct
// t_ for type
typedef struct s_stack
{
	int	value;
	int	i;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;


int	handle_error();
// lets check the input
int is_int(char *arg);
int check_for_dup(char **arg);
int	is_sorted(char **arg);
void insert_end(t_stack **head, int value);
void display(t_stack *head);

// creating nodes
t_stack *create_node(int value);
void insert_end(t_stack **head, int value);
void display(t_stack *head);
int	stack_len(t_stack *stack);
t_stack	*largest_element(t_stack *head);
t_stack	*smallest_element(t_stack *head);
t_stack	*last_node(t_stack *head);


// operations
// swap
void	swap(t_stack **head);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// rotate
void	rotate(t_stack **head);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// reverse_rotate
void	reverse_rotate(t_stack **head);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	sort_three(t_stack **a);

#endif
