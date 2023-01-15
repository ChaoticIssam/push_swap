/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:20:55 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/14 13:43:36 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int arg)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->data = arg;
	newnode->next = NULL;
	return (newnode);
}

void	ft_free2(char **str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free(str);
}

t_node	*create_stack_a(char **av, int ac)
{
	t_dec2	var;

	var.size = ac - 1;
	var.top = NULL;
	var.add_store = NULL;
	var.ptr = NULL;
	while (var.size > 0)
	{
		var.j = -1;
		var.ptr = ft_split(av[var.size], ' ');
		if (var.ptr[0] == NULL)
			error();
		while (var.ptr[++var.j])
			if (!digit_checker(var.ptr) || great_than_limits_checker(var.ptr))
				error();
		while (--var.j >= 0)
		{
			var.top = create_node(ft_atoi(var.ptr[var.j]));
			var.top->next = var.add_store;
			var.add_store = var.top;
		}
		var.size--;
		ft_free2(var.ptr);
	}
	return (var.top);
}
