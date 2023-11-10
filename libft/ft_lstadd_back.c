/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:09:48 by chbuerge          #+#    #+#             */
/*   Updated: 2023/06/01 17:21:09 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Adds the node ’new’ at the end of the list.*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nw;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			nw = ft_lstlast(*(lst));
			nw->next = new;
		}			
	}
}
