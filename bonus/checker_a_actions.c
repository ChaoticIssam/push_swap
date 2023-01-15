/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_a_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:43:56 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/11 17:41:06 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_a(t_node *start)
{
	if (!start)
		return ;
	if (size_count(start) >= 2)
	{
		ft_swaper(&(start->data), &(start->next->data));
	}
}

void	push_a(t_node **stack_b, t_node **stack_a)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!(*stack_b))
		return ;
	if (*stack_a == NULL)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		*stack_a = tmp;
		(*stack_a)->next = NULL;
	}
	else if (*stack_a)
	{
		tmp = *stack_b;
		tmp2 = (*stack_b)->next;
		(*stack_b)->next = *stack_a;
		*stack_a = tmp;
		*stack_b = tmp2;
	}
}

void	rotate_a(t_node **stack_a)
{
	t_node	*tmp;

	if (ft_lstsize(*stack_a) > 2)
	{
		tmp = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		ft_lstadd_back(stack_a, tmp);
		tmp->next = NULL;
	}
	else
		return ;
}

void	reverse_rotate_a(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*tmp_1;

	tmp = (*stack_a);
	tmp_1 = (*stack_a);
	if (ft_lstsize(*stack_a) == 2)
	{
		swap_a(*stack_a);
		return ;
	}
	else if (ft_lstsize(*stack_a) > 2)
	{
		while (tmp->next)
			tmp = tmp->next;
		while (tmp_1->next->next)
			tmp_1 = tmp_1->next;
		tmp->next = (*stack_a);
		(*stack_a) = tmp;
		tmp_1->next = NULL;
	}
}
