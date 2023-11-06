/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:05:03 by chbuerge          #+#    #+#             */
/*   Updated: 2023/11/06 17:30:43 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
 // printf
 #include <stdio.h>
 // atoi
 #include <stdlib.h>
 // exit
 #include <stdlib.h>

typedef struct s_stack
{
	int	value;
	struct s_stack *next;
} t_stack;

#endif
