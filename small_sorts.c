/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:57:20 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/08 09:58:04 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_for_3(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->index;
	second = ((*stack_a)->next)->index;
	third = (((*stack_a)->next)->next)->index;
	if (first < second && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (third < first && first < second)
		rra(stack_a);
	else if (second < third && third < first)
		ra(stack_a);
	else if (second < first && first < third)
		sa(stack_a);
	else if (first < third && third < second)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_for_4(t_list **stack_a, t_list **stack_b)
{
	if (find_minor_position(*stack_a) == 2)
		sa(stack_a);
	while (find_minor_position(*stack_a) >= 3)
		rra(stack_a);
	pb(stack_b, stack_a);
	if (!is_sorted(stack_a))
		sort_for_3(stack_a);
	if (is_inverted(*stack_a))
	{
		ra(stack_a);
		sa(stack_a);
	}
	pa(stack_a, stack_b);
}

void	sort_for_5(t_list **stack_a, t_list **stack_b)
{
	while (find_minor_position(*stack_a) != 1 \
				&& find_minor_position(*stack_a) <= 3)
		ra(stack_a);
	while (find_minor_position(*stack_a) >= 4)
		rra(stack_a);
	pb(stack_b, stack_a);
	sort_for_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
