/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:14:50 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/05 15:10:16 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_error()
{
	write(2, "Error\n", 6);
	exit(1);
}
void	free_errors(t_stack **a)
{
	free_stack(a);
	write (2, "Error\n", 6);
	exit (1);
}
void	free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	if (!stack)
		return ;
	head = *stack;
	while (head)
	{
		tmp = head->next;
		// not nec
		head->value = 0;
		free(head);
		head = tmp;
	}
	*stack = NULL;
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	long		value;

	a = NULL;
	b = NULL;
	i = 0;
	value = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	check_if_int(argv);
	check_for_dup(argv);
	if (check_if_sorted(argv) == 1)
	{
		while (argv[i])
		{
			value = ft_atolong(argv[i]);
			if (value < INT_MIN || value > INT_MAX)
				handle_error();
			insert_end(&a, value);
			i++;
		}

	if (stack_len(a) == 2)
		sa(&a);
	else if (stack_len(a) == 3)
		sort_three(&a);
	else
		sort_stacks(&a, &b);
	}
	if (argc == 2)
	{
	i = 0;
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	free_stack(&a);
	return (0);
}
