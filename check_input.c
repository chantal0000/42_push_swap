/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:41:17 by chbuerge          #+#    #+#             */
/*   Updated: 2023/11/24 12:16:15 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check if all argument values are integer___________________________________________________________________

int is_int(char *arg)
{
	int i;

	i = 0;
	if (arg[i] == '-' && arg[i + 1] || arg[i] == '+' && arg[i + 1])
	{
		i++;
	}
	while(arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			handle_error();
		i++;
	}
	return (0);
}

//check for duplicates within the argument values____________________________________________________________
// **arg because I need to have all args to compare to eachother
int check_for_dup(char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i])
	{
		j = 1;
			while (arg[j])
			{
                // WRONG COMPARE FUNCTION; NOT ALLOWED
				// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				if (i != j && strcmp(arg[i], arg[j]) == 0)
					handle_error();
				else
					j++;
			}
		i++;
	}
	return (0);
}

//check if already sorted___________________________________________________________________________
// !!!! rewrite this with linkedlist


int	is_sorted(char **arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i + 1])
	{
		// NOT ALLOWED FUNCTION
		// meaning its not sorted
		if (strcmp(arg[i], arg[i + 1]) > 0)
// stop here how??
// not exit cause than we exit the whole program
			//exit (1);
			return (1);
			// meaning its sorted
		else
			i++;
			//printf("arg[i]: %s\n", arg[i]);
			//printf("i: %d\n", i);
	}
	// if we get here it means its sorted and we error & exit
	handle_error();
	return (0);
}


//___________________________________________________________________________
