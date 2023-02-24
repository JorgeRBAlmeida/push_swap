/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 00:33:40 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/23 21:42:28 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_arg_number(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (i == 0 && str[i] == '-')
			i ++;
		if (!ft_isdigit(str[i]))
			return (0);
		i ++;
	}
	return (1);
}

int	validate_args(char **argv)
{
	int	i;
	int	j;
	
	i= 1;
	j = 1;
	while (argv[i])
	{
		if (!is_arg_number(argv[i]) ||
			((ft_atoi(argv[i]) > INT_MAX) || \
				( ft_atoi(argv[i]) < INT_MIN)))
			return (0);
		j = i - 1;
		while (i > 1 && j >= 1)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j --;
		}
		i ++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (!validate_args(argv))
			ft_putstr_fd("Error\n", 1);
	}
		return (0);
}
