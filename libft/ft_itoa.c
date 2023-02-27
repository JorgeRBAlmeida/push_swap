/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:39:19 by joalmeid          #+#    #+#             */
/*   Updated: 2022/06/06 12:21:37 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	power_ten(long times);
static long	itoa_nstrlen(int n, long sign);
static long	itoa_nsign(int *n);
static void	itoa_putsign(long *i, long *len, char *str);

char	*ft_itoa(int n)
{
	long	i;
	long	len;
	long	temp;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = itoa_nsign(&n);
	len = itoa_nstrlen(n, i);
	str = ft_calloc((len + 1), sizeof(*str));
	if (str == NULL)
		return (NULL);
	itoa_putsign(&i, &len, str);
	while (len > 0 && n != -2147483648)
	{
		temp = n / power_ten(len - 1);
		str[i] = (temp % 10) + '0';
		len --;
		i ++;
	}
	str[i] = '\0';
	return (str);
}

static long	itoa_nsign(int *n)
{
	long	sign;

	sign = 0;
	if (*n < 0)
	{
		sign = 1;
		*n = *n * (-1);
	}
	return (sign);
}

static long	itoa_nstrlen(int n, long sign)
{
	long	len;

	len = 1;
	if (sign)
		len += sign;
	while (n > 9)
	{
		n = (n / 10);
		len ++;
	}
	return (len);
}

static void	itoa_putsign(long *i, long *len, char *str)
{
	if (*i)
	{
		str[0] = '-';
		*len = *len - 1;
	}
}

static long	power_ten(long times)
{
	long	i;

	i = 10;
	if (times == 0)
		return (1);
	if (times == 1)
		return (10);
	while (times > 1)
	{
		i = i * 10;
		times --;
	}
	return (i);
}
