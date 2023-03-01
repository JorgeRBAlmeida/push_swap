/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:23:48 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/01 20:46:24 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;

	first = *stack_a;
	if (is_sorted(stack_a))
		return ;
	else if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else if (is_inverted((*stack_a)))
		uninvert_stack(stack_a, stack_b);
}

void	uninvert_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	
	last = ft_lstlast(*stack_a);
	if (ft_lstsize(*stack_a) == 3)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else
	{
		while ((*stack_a)->next != NULL)
		{
			rra(stack_a);
			pb(stack_b, stack_a);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
	}
	*stack_a = last;
}

/* void	sort_for_3(t_list **stack_a, t_list **stack_b)
{
	
}

void	sort_for_5(t_list **stack_a, t_list **stack_b)
{
	
}

void	sort_for_rest(t_list **stack_a, t_list **stack_b)
{
	
} */
