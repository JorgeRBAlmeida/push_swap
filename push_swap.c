/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 00:33:40 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/28 14:42:49 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**new_argv;
	t_list	*stack_a;
	t_list	*tmp;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	tmp = NULL;
	if (argc > 1)
	{
		new_argv = remove_space_argv(argv);
		if (!validate_args(new_argv))
			ft_putstr_fd("Error\n", 1);
		else
		{
			create_stack_a(&stack_a, new_argv);
			ra(&stack_a);
			print_lst(stack_a, "A");
		}
		free_new_argv(new_argv);
	}
	while (stack_a != NULL)
	{
		tmp = stack_a->next;
		free(stack_a->content);
		free(stack_a);
		stack_a = tmp;
	}
	return (0);
}
