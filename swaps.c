/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:02:03 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/28 11:08:23 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_next_node(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;

	if ((*stack)->next == NULL)
		return ;
	//temp aponta para 1º elemento
	temp = *stack;
	//stack anda para 2º elemento
	*stack = (*stack)->next;
	//temp2 aponta 3ºelemento
	temp2 = (*stack)->next;
	//segundo elemento aponta para temp
	(*stack)->next = temp;
	temp->next = temp2;	
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
