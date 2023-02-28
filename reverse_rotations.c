/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:26:03 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/27 19:41:13 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_stack(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	last = ft_lstlast(*stack);
	while ((*stack)->next == last)
		*stack = (*stack)->next;
	(*stack)->next = NULL;
	ft_lstadd_front(&first, last);
}

void	rra(t_list **stack_a)
{
	rev_rotate_stack(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rrb(t_list **stack_b)
{
	rev_rotate_stack(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate_stack(stack_a);
	rev_rotate_stack(stack_b);
	ft_putstr_fd("rr\n", 1);
}