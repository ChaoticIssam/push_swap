/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:19:44 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/10 13:20:01 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == 32)
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	long				i;
	long				sign;
	unsigned long long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = result * 10 + str[i++] - '0';
	return (result * sign);
}

void	ft_swaper(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
