/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:26:03 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/07 13:09:16 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_stack(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	last = ft_lstlast(*stack);
	while (*stack)
	{
		if ((*stack)->next == last)
			(*stack)->next = NULL;
		*stack = (*stack)->next;
	}
	*stack = first;
	ft_lstadd_front(stack, last);
}

void	rra(t_list **stack_a)
{
	rev_rotate_stack(stack_a);
	print_action("rra\n");
}

void	rrb(t_list **stack_b)
{
	rev_rotate_stack(stack_b);
	print_action("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate_stack(stack_a);
	rev_rotate_stack(stack_b);
	print_action("rrr\n");
}
