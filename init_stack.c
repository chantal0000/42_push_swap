/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:10:26 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/06 18:24:05 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **a, int count_input, char **input)
{
	long	value;
	int		i;

	i = 0;
	check_input(count_input, input);
	while (input[i])
	{
		value = ft_atolong(input[i]);
		insert_end(a, value);
		i++;
	}
}

long	ft_atolong(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	if (sign == -1)
	{
		return (result * sign);
	}
	return (result);
}
