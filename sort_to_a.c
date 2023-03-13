/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:11:05 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/10 08:29:24 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_major_at_top_b(t_list **stack_a, t_list **stack_b, \
														t_push set, int major)
{
	if (set.top_or_botton == 1 && (*stack_b)->index != major)
	{
		if ((*stack_b)->index == major - 1 \
				&& (*stack_b)->next->index == major)
			sb(stack_b);
		else if ((ft_lstlast(*stack_a)->index == set.size || \
			(*stack_b)->index > ft_lstlast(*stack_a)->index))
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else
			rb(stack_b);
	}
	if (set.top_or_botton == 2 && (*stack_b)->index != major)
		rrb(stack_b);
}

static void	push_major_to_a(t_list **stack_a, t_list **stack_b, int *major)
{
	if ((*stack_b)->index == *major)
	{
		pa(stack_a, stack_b);
		*major -= 1;
	}
}

static void	handle_major_bottom_a(t_list **stack_a, int *major, t_push set)
{
	while (ft_lstlast(*stack_a)->index != set.size \
		&& ft_lstlast(*stack_a)->index == *major)
	{
		rra(stack_a);
		*major -= 1;
	}
}

void	push_back_a(t_list **stack_a, t_list **stack_b, t_push set)
{
	int	major;

	major = set.size;
	while (*stack_b && major)
	{
		if (find_stack_position(major, *stack_b))
		{
			set = set_push_stategy(*stack_b, major, major, set.size);
			put_major_at_top_b(stack_a, stack_b, set, major);
			push_major_to_a(stack_a, stack_b, &major);
		}
		handle_major_bottom_a(stack_a, &major, set);
	}
}
