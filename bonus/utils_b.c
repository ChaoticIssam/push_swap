/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:39:20 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/13 12:28:11 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	ft_strncmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] || s1[i])
	{
		if (s2[i] != s1[i])
			return (s2[i] - s1[i]);
		i++;
	}
	return (0);
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
