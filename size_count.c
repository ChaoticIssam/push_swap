/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:17:55 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/09 21:18:22 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_count(t_node *stack)
{
	int		count;
	t_node	*tmp;

	count = 0;
	if (stack == NULL)
		return (0);
	tmp = stack;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	get_index(t_node *stack_a, int data)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->data == data)
			break ;
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

int	get_min(t_node *stack_a)
{
	t_node	*tmp;
	int		min;

	tmp = NULL;
	tmp = stack_a;
	min = tmp->data;
	while (tmp->next)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	if (tmp->data < min)
		min = tmp->data;
	return (min);
}

int	get_max(t_node *stack_b)
{
	t_node	*tmp;
	int		max;

	tmp = NULL;
	tmp = stack_b;
	max = tmp->data;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}
