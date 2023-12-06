/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:41:17 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/06 18:36:56 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(int count_input, char **input)
{
	check_if_int(count_input, input);
	check_for_dup(count_input, input);
}

//check if all argument values are integer
int	check_if_int(int count_input, char **input)
{
	int	i;
	int	j;

	j = 0;
	while (input[j])
	{
		i = 0;
		if ((input[j][i] == '-' && input[j][i + 1])
			|| (input[j][i] == '+' && input[j][i + 1]))
			i++;
		while (input[j][i])
		{
			if (input[j][i] < '0' || input[j][i] > '9')
				handle_error(count_input, input);
			i++;
		}
		if (ft_atolong(input[j]) < INT_MIN || ft_atolong(input[j]) > INT_MAX)
			handle_error(count_input, input);
		j++;
	}
	return (0);
}

//check for duplicates within the argument values
int	check_for_dup(int count_input, char **input)
{
	int		i;
	int		j;
	long	num1;
	long	num2;

	i = 0;
	while (input[i])
	{
		j = i + 1;
		while (input[j])
		{
			num1 = ft_atolong(input[i]);
			num2 = ft_atolong(input[j]);
			if (num1 == num2)
				handle_error (count_input, input);
			j++;
		}
		i++;
	}
	return (0);
}

/*
int	check_for_dup(char **arg)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (arg[i])
	{
		j = 0;
		len = 0;
		while (arg[j])
		{
			if (ft_strlen(arg[i]) >= ft_strlen(arg[j]))
				len = ft_strlen(arg[i]);
			else if (ft_strlen(arg[i]) < ft_strlen(arg[j]))
				len = ft_strlen(arg[j]);
			if (i != j && ft_strncmp(arg[i], arg[j], len) == 0)
				handle_error();
			else
				j++;
		}
		i++;
	}
	return (0);
}*/

// check if sorted of a linked list
int	check_if_sorted_list(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (2);
		stack = stack->next;
	}
	return (0);
}
