/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_zaydin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:51:32 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/11 19:06:54 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_a(*stack_a);
	swap_b(*stack_b);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
