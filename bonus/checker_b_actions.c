/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_b_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:45:26 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/14 14:12:45 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_b(t_node *start)
{
	if (size_count(start) < 2)
		return ;
	if (start->next)
	{
		ft_swaper(&(start->data), &(start->next->data));
	}
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (*stack_a == NULL)
		return ;
	if (*stack_b == NULL)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		*stack_b = tmp;
		(*stack_b)->next = NULL;
	}
	else if (*stack_b)
	{
		tmp = *stack_a;
		tmp2 = (*stack_a)->next;
		(*stack_a)->next = *stack_b;
		*stack_b = tmp;
		*stack_a = tmp2;
	}
}

void	rotate_b(t_node **stack_b)
{
	t_node	*tmp;

	if (size_count(*stack_b) < 2)
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	ft_lstadd_back(stack_b, tmp);
	tmp->next = NULL;
}

void	reverse_rotate_b(t_node **stack_b)
{
	t_node	*tmp;
	t_node	*tmp_1;

	tmp = (*stack_b);
	tmp_1 = (*stack_b);
	if (size_count(*stack_b) < 2)
		return ;
	if (ft_lstsize(*stack_b) == 2)
	{
		swap_b(*stack_b);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	while (tmp_1->next->next)
		tmp_1 = tmp_1->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	tmp_1->next = NULL;
}
