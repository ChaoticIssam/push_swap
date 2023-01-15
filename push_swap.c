/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:18:49 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/15 13:24:37 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_size(t_dec3 var)
{
	var.i = 0;
	if (var.size == 2)
		swap_a(var.stack_a);
	else if (var.size == 3)
		its_three(&var.stack_a);
	else if (var.size > 3 && var.size <= 16)
		its_five(&var.stack_a, &var.stack_b);
	else
	{
		while (var.i < size_count(var.stack_a))
		{
			sort_array(var.stack_a, var.ptr);
			var.i++;
		}
		its_hundred_omg(&var.stack_a, &var.stack_b, var.ptr);
		back_to_a(&var.stack_b, &var.stack_a, var.ptr);
	}
}

int	main(int ac, char **av)
{
	t_dec3	var;

	var.stack_a = NULL;
	var.stack_b = NULL;
	var.stack_a = create_stack_a(av, ac);
	var.size = size_count(var.stack_a);
	if (ac == 1)
		exit(1);
	if (duplication_checker(&var.stack_a))
		error();
	if (is_sorted(var.stack_a))
		return (0);
	var.ptr = array_maker(var.stack_a);
	check_size(var);
}
