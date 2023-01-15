/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:22:28 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/13 11:58:18 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*array_maker(t_node *stack_a)
{
	int	*str;
	int	i;

	i = 0;
	str = malloc(sizeof(int) * size_count(stack_a));
	if (!str)
		return (0);
	while (stack_a)
	{
		str[i] = stack_a->data;
		stack_a = stack_a->next;
		i++;
	}
	return (str);
}

void	sort_array(t_node *stack_a, int *str)
{
	int	i;
	int	j;
	int	size;
	int	save;

	size = size_count(stack_a);
	j = 1;
	while (j < size)
	{
		save = str[j];
		i = j - 1;
		while (i >= 0 && str[i] > save)
		{
			str[i + 1] = str[i];
			i--;
		}
		str[i + 1] = save;
		j++;
	}
}
