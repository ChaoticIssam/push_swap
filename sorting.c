/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:15:59 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/13 11:44:29 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	its_three(t_node **stack_a)
{
	int	i;
	int	j;
	int	k;

	i = (*stack_a)->data;
	j = (*stack_a)->next->data;
	k = (*stack_a)->next->next->data;
	if (i < j && j > k && i < k)
	{
		reverse_rotate_a(stack_a);
		swap_a(*stack_a);
	}
	else if (i > j && i < k)
		swap_a(*stack_a);
	else if (i < j && i > k && j > k)
		reverse_rotate_a(stack_a);
	else if (i > j && i > k && j < k)
		rotate_a(stack_a);
	else if (i > j && i > k && j > k)
	{
		swap_a(*stack_a);
		reverse_rotate_a(stack_a);
	}
}

void	get_elm_intop(t_node **stack, int elm)
{
	int		x;
	t_node	*tmp;

	tmp = *stack;
	if (max_exist(*stack, elm))
	{
		x = get_index(*stack, elm);
		if (x <= ft_lstsize(*stack) / 2)
		{
			while ((*stack)->data != elm)
				rotate_a(stack);
		}
		else
		{
			while ((*stack)->data != elm)
				reverse_rotate_a(stack);
		}
	}
}

void	its_five(t_node **stack_a, t_node **stack_b)
{
	int	min;

	while (ft_lstsize(*stack_a) > 3)
	{
		min = get_min(*stack_a);
		get_elm_intop(stack_a, min);
		push_b(stack_a, stack_b);
	}
	its_three(stack_a);
	while (*stack_b)
		push_a(stack_b, stack_a);
}

void	its_hundred_omg(t_node **a, t_node **b, int *ar)
{
	t_dec	*v;

	v = malloc(sizeof(t_dec));
	check_list_size(v, a);
	while (*a)
	{
		v->index = is_exist(a, ar, v->s, v->e);
		if (v->index < size_count(*a))
		{
			if (v->index <= size_count(*a) / 2)
			{
				while (!((*a)->data >= ar[v->s] && (*a)->data <= ar[v->e]))
					rotate_a(a);
			}
			else
			{
				while (!((*a)->data >= ar[v->s] && (*a)->data <= ar[v->e]))
					reverse_rotate_a(a);
			}
			ft_push(a, b, ar, v);
		}
		else
			increase_range(v);
	}
	free(v);
}

void	back_to_a(t_node **b, t_node **a, int *ar)
{
	t_dec4	*v;

	v = malloc(sizeof(t_dec4));
	v->count = 0;
	v->size_ar = size_count(*b) - 1;
	while (*b || v->size_ar >= 0)
	{
		v->size_sb = size_count(*b);
		if (max_exist(*b, ar[v->size_ar]))
		{
			if ((*b)->data == ar[v->size_ar])
				max_first(b, a, v);
			else if (v->count == 0 || (*b)->data > get_last_elem(*a)->data)
				push_rotate_a(b, a, v);
			else
				max_in_b(b, ar, v);
		}
		else
			no_max_there(a, v);
	}
	free(v);
}
