/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:49:18 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/12 18:09:19 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	duplication_checker(t_node **stack_a)
{
	t_node	*i;
	t_node	*j;

	if (stack_a == NULL)
		return (0);
	i = *stack_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->data == j->data)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

void	error(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(1);
}

int	is_sorted(t_node *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
