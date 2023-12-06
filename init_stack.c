/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:10:26 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/06 09:20:36 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **a, char **argv)
{
	long	value;
	int		i;

	i = 0;
	check_input(argv);
	while (argv[i])
	{
		value = ft_atolong(argv[i]);
		// &a -> should it be??!!
		insert_end(a, value);
		i++;
	}
}
