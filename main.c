/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:14:50 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/06 18:37:22 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_error(int count_input, char **input)
{
	write(2, "Error\n", 6);
	if (count_input == 2)
		free_array(input);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**input;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
		input = ft_split(argv[1], ' ');
	else
		input = argv + 1;
	init_stack(&a, argc, input);
	if (check_if_sorted_list(a) == 2)
		start_sort(&a, &b);
	if (argc == 2)
		free_array(input);
	free_stack(&a);
	return (0);
}
