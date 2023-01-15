/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:21:13 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/15 13:24:30 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_dec3	var;
	char	*tmp;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = create_stack_a(av, ac);
	var.size = size_count(stack_a);
	if (ac == 1)
		exit(1);
	if (duplication_checker(&stack_a))
		error();
	while (1)
	{
		tmp = get_next_line(0);
		if (tmp == NULL)
			break ;
		operations(tmp, &stack_a, &stack_b);
		free(tmp);
	}
	if (is_sorted(stack_a) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
