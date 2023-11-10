/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:14:50 by chbuerge          #+#    #+#             */
/*   Updated: 2023/11/10 10:28:06 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_error()
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*a;
	t_stack *b;
	int value;

	a = NULL;
	b = NULL;
	i = 1;
	value = 0;
	if (argc < 2)
		handle_error();
	else if (argc > 2)
	{
		while (argv[i])
		{
			is_int(argv[i]);
			i++;
		}
		check_for_dup(argv);
		// meaning its not sorted, then we do what?
		if (is_sorted(argv) == 1)
		{
		// init stack a
		// +1 to start from the second element of the command line argument
		//init_stack_a(&a, argv + 1);
			i = 1;
			while(i < argc)
			{
				value = ft_atoi(argv[i]);
				insert_end(&a, value);
				i++;
			}
			display(a);
		}
	}
	return (0);
}
