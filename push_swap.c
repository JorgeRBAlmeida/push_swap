/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 00:33:40 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/02 20:32:52 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**new_argv;
	t_list	*stack_a;
	t_list	*stack_b;
	t_push	set;

	stack_a = NULL;
	stack_b = NULL;
	set.half = 0;
	set.minor_qnt = 0;
	set.size_half = 0;
	if (argc > 1)
	{
		new_argv = remove_space_argv(argv);
		if (!validate_args(new_argv))
			ft_putstr_fd("Error\n", 1);
		else
		{
			create_stack_a(&stack_a, new_argv);
			//print_lst(stack_a, "antes A");
			//sort_stack_a(&stack_a, &stack_b);
			set.size_half = ft_lstsize(stack_a) / 2;;
			set.half = get_most_minor_half(stack_a, set.size_half, &set.minor_qnt);
			push_minor_b(&stack_a, &stack_b, set);
			print_lst(stack_a, "A");
			print_lst(stack_b, "B");
			/* sort_stack_a(&stack_a, &stack_b);
			print_lst(stack_a, "A depois da func"); */
			/* if (sort_stack_a(&stack_a))
				ft_putstr_fd("\ninvertida\n", 1);
			else
				ft_putstr_fd("\nnão invertida\n", 1); */
		}
		free_new_argv(new_argv);
	}
	free_stacks(&stack_a, &stack_b);
	return (0);
}
