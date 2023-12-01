/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:31:51 by chbuerge          #+#    #+#             */
/*   Updated: 2023/11/30 11:44:52 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **split(char *str, char *sepertors, int *count)
{
	int	len;
	int	i;
	int	old_i;
	char **new_string;

	len = ft_strlen(str);
	*count = 0;
	i = 0;
	old_i = 0;
	while (i < len)
	{
		while (i < len)
		{
			if (ft_strchr(sepertors, str[i]) == NULL)
				break;
			i++;
		}
		old_i = i;
		while (i < len)
		{
			if (ft_strchr(sepertors, str[i] != NULL))
				break;
			i++;
		}
		if (i > old_i)
			count++;
	}

	new_string = malloc(sizeof(char*) * *count);

}
