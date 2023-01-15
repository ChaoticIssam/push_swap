/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:22:14 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/12 15:24:57 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_node *start)
{
	if (!(start->data) || start->next == NULL || (!(start->data)
			&& start->next == NULL))
		return ;
	if (start->next)
	{
		ft_swaper(&(start->data), &(start->next->data));
	}
	write(1, "sb\n", 3);
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
	write(1, "pb\n", 3);
}

void	rotate_b(t_node **stack_b)
{
	t_node	*tmp;

	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	ft_lstadd_back(stack_b, tmp);
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	reverse_rotate_b(t_node **stack_b)
{
	t_node	*tmp;
	t_node	*tmp_1;

	tmp = (*stack_b);
	tmp_1 = (*stack_b);
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
	write(1, "rrb\n", 4);
}
