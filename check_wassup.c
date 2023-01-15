/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wassup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:22:02 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/14 21:54:47 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isit_int(char *ptr)
{
	int	i;

	i = 0;
	if (ptr[i] == '-' || ptr[i] == '+')
		i++;
	if (!ptr[i] && i)
	{
		free(ptr);
		error();
	}
	while (ptr[i])
	{
		if (!ft_isdigit(ptr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	digit_checker(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (!isit_int(ptr[i]))
			return (0);
		i++;
	}
	return (1);
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

int	great(char *arg)
{
	return (ft_atoi(arg) < INT_MIN || ft_atoi(arg) > INT_MAX);
}

int	great_than_limits_checker(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (great(av[i]))
			return (1);
		i++;
	}
	return (0);
}
