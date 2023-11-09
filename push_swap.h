/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:05:03 by chbuerge          #+#    #+#             */
/*   Updated: 2023/11/08 12:51:34 by chbuerge         ###   ########.fr       */
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

// s_ for struct
// t_ for type
typedef struct s_stack
{
	int	value;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

#endif
