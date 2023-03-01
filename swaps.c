/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:02:03 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/01 16:16:18 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_next_node(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	if ((*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp2 = (*stack)->next;
	(*stack)->next = tmp;
	tmp->next = tmp2;
}

void	sa(t_list **stack_a)
{
	swap_next_node(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **stack_b)
{
	swap_next_node(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap_next_node(stack_a);
	swap_next_node(stack_b);
	ft_putstr_fd("ss\n", 1);
}
