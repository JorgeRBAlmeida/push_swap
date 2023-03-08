/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:10:46 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/08 14:54:02 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_range_b(t_list **stack_a, t_list **stack_b, t_push set)
{
	int	ranged;

	ranged = set.qnt;
	while (*stack_a != NULL && ranged > 0)
	{
		if (*stack_a && (*stack_a)->index >= set.init \
								&& (*stack_a)->index <= set.end)
		{
			optmize_push_b(stack_a, stack_b, set);
			pb(stack_b, stack_a);
			if ((*stack_b)->index <= set.init + 16 && set.size > 400)
				rb(stack_b);
			else if ((*stack_b)->index < set.qnt / 2 + set.qnt % 2 \
													&& set.size < 400)
				rb(stack_b);
			optmize_b(stack_a, stack_b, set);
			ranged --;
		}
		else if (*stack_a && set.top_or_botton == 1)
			ra(stack_a);
		else if (*stack_a && set.top_or_botton == 2)
			ra(stack_a);
	}
}
