/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:22:37 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/10 13:29:42 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node *start)
{
	if (!start)
		return ;
	if (size_count(start) >= 2)
	{
		ft_swaper(&(start->data), &(start->next->data));
	}
	write(1, "sa\n", 3);
}

void	push_a(t_node **stack_b, t_node **stack_a)
{
	t_node	*tmp;
	t_node	*tmp2;

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
	write(1, "pa\n", 3);
}

void	rotate_a(t_node **stack_a)
{
	t_node	*tmp;

	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	ft_lstadd_back(stack_a, tmp);
	tmp->next = NULL;
	write(1, "ra\n", 3);
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
	while (tmp->next)
		tmp = tmp->next;
	while (tmp_1->next->next)
		tmp_1 = tmp_1->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	tmp_1->next = NULL;
	write(1, "rra\n", 4);
}
