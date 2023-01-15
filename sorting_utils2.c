/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:38:39 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/10 14:51:26 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	no_max_there(t_node **a, t_dec4 *v)
{
	reverse_rotate_a(a);
	v->count--;
	v->size_ar--;
}

void	max_in_b(t_node **b, int *ar, t_dec4 *v)
{
	if (get_index(*b, ar[v->size_ar]) <= v->size_sb / 2)
		while ((*b)->data != ar[v->size_ar])
			rotate_b(b);
	else
		while ((*b)->data != ar[v->size_ar])
			reverse_rotate_b(b);
}
