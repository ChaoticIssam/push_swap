/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_to_do_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:04:16 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/13 12:22:33 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	operations(char *tmp, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(tmp, "sa\n") == 0)
		swap_a(*stack_a);
	else if (ft_strncmp(tmp, "pa\n") == 0)
		push_a(stack_b, stack_a);
	else if (ft_strncmp(tmp, "ra\n") == 0)
		rotate_a(stack_a);
	else if (ft_strncmp(tmp, "rra\n") == 0)
		reverse_rotate_a(stack_a);
	else if (ft_strncmp(tmp, "sb\n") == 0)
		swap_b(*stack_b);
	else if (ft_strncmp(tmp, "pb\n") == 0)
		push_b(stack_a, stack_b);
	else if (ft_strncmp(tmp, "rb\n") == 0)
		rotate_b(stack_b);
	else if (ft_strncmp(tmp, "rrb\n") == 0)
		reverse_rotate_b(stack_b);
	else if (ft_strncmp(tmp, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(tmp, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(tmp, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else
		error();
}
