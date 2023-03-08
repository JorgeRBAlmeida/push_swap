/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 00:33:40 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/08 15:14:51 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**new_argv;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		new_argv = remove_space_argv(argv);
		if (!validate_args(new_argv))
			ft_putstr_fd("Error\n", 2);
		else
		{
			create_stack_a(&stack_a, new_argv);
			push_swap(&stack_a, &stack_b);
		}
		free_new_argv(new_argv);
	}
	free_stacks(&stack_a, &stack_b);
	return (0);
}
