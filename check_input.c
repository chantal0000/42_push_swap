/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:41:17 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/01 11:59:02 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check if all argument values are integer
int	check_if_int(char **arg)
{
	int i;
	int j;

	j = 0;
	while (arg[j])
	{
		i = 0;
		if (arg[j][i] == '-' && arg[j][i + 1]
			|| arg[j][i] == '+' && arg[j][i + 1])
			i++;
		while(arg[j][i])
		{
			if (arg[j][i] < '0' || arg[j][i] > '9')
				handle_error();
			i++;
		}
		j++;
	}
	return (0);
}

//check for duplicates within the argument values_______________________________
int	check_for_dup(char **arg)
{
	int	i;
	int	j;
	int len;

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
}

//check if already sorted___________________________________________________________________________


int	check_if_sorted(char **arg)
{
	int	i;
	int	len;

	i = 0;
	while (arg[i] && arg[i + 1])
	{
		len = ft_strlen(arg[i]);
		if (ft_strncmp(arg[i], arg[i + 1], len) > 0)
			return (1);
			// meaning its sorted
		else
			i++;
	}
	// if we get here it means its sorted and we error & exit
	handle_error();
	return (0);
}
//___________________________________________________________________________
