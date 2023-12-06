/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:05:03 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/06 18:30:21 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
// boolean function
# include <stdbool.h>
// write
# include <unistd.h>
// printf
# include <stdio.h>
// atoi, exit
# include <stdlib.h>
// strcmp
# include <string.h>
// int max and min
# include <limits.h>
// libft
# include "./libft/libft.h"

// s_ for struct
// t_ for type
typedef struct s_stack
{
	int				value;
	int				i;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
	int				operations_cost;
	bool			above_median;
	bool			cheapest;

}	t_stack;

int		handle_error(int count_input, char **input);
// CHECK INPUT
void	check_input(int count_input, char **input);
int		check_if_int(int count_input, char **input);
int		check_for_dup(int count_input, char **input);
int		check_if_sorted_list(t_stack *stack);

// INIT STACK
void	init_stack(t_stack **a, int count_input, char **input);
long	ft_atolong(const char *str);

// CREATE NODES
t_stack	*create_node(int value);
void	insert_end(t_stack **head, int value);
//void display(t_stack *head);

// SORTING
void	start_sort(t_stack	**a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_stacks(t_stack **a, t_stack **b);
void	set_data_a(t_stack *a, t_stack *b);

// FIND NODE TO PUSH
void	node_index(t_stack *stack);
void	find_target_node_for_a(t_stack *a, t_stack *b);
void	operation_cost(t_stack *a, t_stack *b);
void	find_cheapest(t_stack *b);

// A TO B
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	move_to_top(t_stack **stack, t_stack *top_node, char stack_name);
void	prepare_and_push_cheapest_a_to_b(t_stack **a, t_stack **b);
t_stack	*get_cheapest(t_stack *stack);

// PREP B
void	find_target_node_for_b(t_stack *a, t_stack *b);
void	set_data_b(t_stack *a, t_stack *b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);
void	prep_for_push(t_stack **stack, t_stack *top_node);

// UTILS_NODES
t_stack	*last_node(t_stack *head);
t_stack	*largest_element(t_stack *head);
t_stack	*smallest_element(t_stack *head);
int		stack_len(t_stack *stack);

// OPERATIONS
	// SWAP
void	swap(t_stack **head);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

	// ROTATE
void	rotate(t_stack **head);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

	// REVERSE_ROTATE
void	reverse_rotate(t_stack **head);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

	// PUSH
void	push(t_stack **source, t_stack **destination);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

// FREE
void	free_array(char **argv);
void	free_stack(t_stack **stack);

#endif
