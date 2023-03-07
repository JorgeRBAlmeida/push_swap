/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:09:09 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/07 13:08:41 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	last = ft_lstlast(*stack);
	last->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	ra(t_list **stack_a)
{
	rotate_stack(stack_a);
	print_action("ra\n");
}

void	rb(t_list **stack_b)
{
	rotate_stack(stack_b);
	print_action("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	print_action("rr\n");
}
