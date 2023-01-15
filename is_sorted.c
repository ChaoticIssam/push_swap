/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:20:43 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/14 16:37:28 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_exist(t_node **stack_a, int *ar, int start, int end)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->data >= ar[start] && tmp->data <= ar[end])
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	max_exist(t_node *stack, int elm)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (elm == tmp->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_node	*get_last_elem(t_node *stack)
{
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}
