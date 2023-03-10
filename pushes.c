/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:08:30 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/07 13:10:25 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node(t_list **stack, t_list **head)
{
	t_list	*first;

	first = *head;
	*head = (*head)->next;
	first->next = NULL;
	ft_lstadd_front(stack, first);
}

void	pa(t_list **stack_a, t_list **head_b)
{
	push_node(stack_a, head_b);
	print_action("pa\n");
}

void	pb(t_list **stack_b, t_list **head_a)
{
	push_node(stack_b, head_a);
	print_action("pb\n");
}
