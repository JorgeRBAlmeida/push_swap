/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 00:33:40 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/27 11:44:35 by joalmeid         ###   ########.fr       */
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

/* int	validate_args(char **argv)
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
} */

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
	t_list	*stack_a;
	//t_list	stack_b;

	//stack_b = NULL;
	stack_a = malloc(sizeof(t_list));
	if (stack_a == NULL)
		return (0);
	if (argc > 1)
	{
		if (!validate_args(argv))
			ft_putstr_fd("Error\n", 1);
		else
			create_stack_a(&stack_a, argv);
		print_lst(&stack_a);
	}
	free(stack_a);
		return (0);
}
