/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:47:51 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/10 14:37:23 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	increase_range(t_dec *var)
{
	var->s -= var->offset;
	var->e += var->offset;
	if (var->s < 0)
		var->s = 0;
	if (var->e > var->size)
		var->e = var->size;
}

void	check_list_size(t_dec *var, t_node **stack_a)
{
	var->size = size_count(*stack_a) - 1;
	if (size_count(*stack_a) <= 150)
		var->offset = size_count(*stack_a) / 8;
	else
		var->offset = size_count(*stack_a) / 18;
	var->mid = var->size / 2;
	var->s = var->mid - var->offset;
	var->e = var->mid + var->offset;
}

void	ft_push(t_node **stack_a, t_node **stack_b, int *ar, t_dec *var)
{
	push_b(stack_a, stack_b);
	if ((*stack_b)->data < ar[var->mid])
		rotate_b(stack_b);
}

void	push_rotate_a(t_node **b, t_node **a, t_dec4 *v)
{
	push_a(b, a);
	rotate_a(a);
	v->count++;
}

void	max_first(t_node **b, t_node **a, t_dec4 *v)
{
	push_a(b, a);
	v->size_ar--;
}
