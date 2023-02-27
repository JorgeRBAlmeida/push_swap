/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:50:12 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/27 11:36:30 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long	has_sign(char c, long *sign);

long	ft_atoi(const char *str)
{
	long	i;
	long	result;
	long	sign;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i ++;
	if (has_sign(str[i], &sign))
		i ++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i ++;
	}
	return (result * sign);
}

static	long	has_sign(char c, long *sign)
{
	if (c == '+')
		return (1);
	if (c == '-')
	{
		*sign = -1;
		return (1);
	}
	return (0);
}
