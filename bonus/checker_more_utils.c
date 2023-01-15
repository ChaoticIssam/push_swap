/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_more_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:53:36 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/14 22:02:35 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	isit_int(char *ptr)
{
	int	i;

	i = 0;
	if (ptr[i] == '-' || ptr[i] == '+')
		i++;
	if (!ptr[i] && i)
		error();
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

int	size_count(t_node *stack)
{
	int		count;
	t_node	*tmp;

	count = 0;
	if (stack == NULL)
		return (0);
	tmp = stack;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
