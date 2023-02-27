/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:39:41 by joalmeid          #+#    #+#             */
/*   Updated: 2022/05/22 16:51:53 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	min_intcase(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		n = min_intcase(n, fd);
	else if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	if (n >= 0 && n <= 9)
		ft_putchar_fd((n + '0'), fd);
	else
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
}

static int	min_intcase(int n, int fd)
{
	n = n / 10;
	ft_putnbr_fd(n, fd);
	return (8);
}
