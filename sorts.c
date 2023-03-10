/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:23:48 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/09 12:31:50 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (is_sorted(stack_a))
		return ;
	else if (stack_size == 2)
		sa(stack_a);
	else if (is_inverted((*stack_a)))
		uninvert_stack(stack_a, stack_b, stack_size);
	else if (stack_size == 3)
		sort_for_3(stack_a);
	else if (stack_size == 4)
		sort_for_4(stack_a, stack_b);
	else if (stack_size == 5)
		sort_for_5(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b, stack_size);
	print_action("final move");
}

void	uninvert_stack(t_list **stack_a, t_list **stack_b, int stack_size)
{
	t_list	*last;

	last = ft_lstlast(*stack_a);
	if (stack_size == 3)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else
	{
		while ((((*stack_a)->next)->next)->next != NULL)
		{
			rra(stack_a);
			pb(stack_b, stack_a);
		}
		sa(stack_a);
		rra(stack_a);
		while (*stack_b)
			pa(stack_a, stack_b);
	}
	*stack_a = last;
}

void	big_sort(t_list **stack_a, t_list **stack_b, int stack_size)
{
	t_push	set;

	set.init = stack_size / 2 + stack_size % 2 - 17;
	set.end = stack_size / 2 + stack_size % 2 + 17;
	while (*stack_a && stack_size >= 400)
	{
		set = set_push_stategy(*stack_a, set.init, set.end, stack_size);
		push_range_b(stack_a, stack_b, set);
		set.init -= 17;
		set.end += 17;
	}
	set.init = 1;
	set.end = 14;
	while (*stack_a && stack_size < 400)
	{
		set.end += 14;
		set = set_push_stategy(*stack_a, set.init, set.end, stack_size);
		push_range_b(stack_a, stack_b, set);
	}
	set.size = stack_size;
	push_back_a(stack_a, stack_b, set);
}
