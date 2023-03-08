/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:01:13 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/08 10:47:13 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_stack_position(int index, t_list *node)
{
	int		position;
	t_list	*head;

	head = node;
	position = 1;
	while (node->next != NULL)
	{
		if (node->index == index)
			return (position);
		node = node->next;
		position ++;
	}
	if ((position == ft_lstsize(head)) \
				&& ((ft_lstlast(head))->index != index))
		position = 0;
	return (position);
}

int	find_minor_position(t_list *node)
{
	int		position;
	int		minor;
	t_list	*head;

	head = node;
	position = 0;
	minor = node->index;
	node = node->next;
	if (node == NULL)
		return (-1);
	while (node != NULL)
	{
		if (minor > node->index)
			minor = node->index;
		node = node->next;
	}
	position = find_stack_position(minor, head);
	return (position);
}

t_push	set_push_stategy(t_list *stack, int init, int end, int stack_size)
{
	int		first_qnt;
	int		second_qnt;
	int		first_p;
	t_push	set;

	first_qnt = 0;
	second_qnt = 0;
	first_p = ft_lstsize(stack) / 2 + ft_lstsize(stack) % 2;
	set.init = init;
	set.end = end;
	set.top_or_botton = 1;
	set.size = stack_size;
	while (stack)
	{
		if (stack->index >= init && stack->index <= end && first_p > 0)
			first_qnt ++;
		else if (stack->index >= init && stack->index <= end && first_p <= 0)
			second_qnt ++;
		first_p --;
		stack = stack->next;
	}
	set.qnt = first_qnt + second_qnt;
	if (first_qnt < second_qnt)
		set.top_or_botton = 2;
	return (set);
}

void	optmize_b(t_list **stack_a, t_list **stack_b, t_push set)
{
	if (*stack_b && (*stack_b)->index < ft_lstlast((*stack_b))->index \
							&& (ft_lstlast((*stack_b))->index >= set.init \
							&& ft_lstlast((*stack_b))->index <= set.end))
	{
		if (*stack_a && (*stack_a)->index > ft_lstlast((*stack_a))->index)
			rrr(stack_a, stack_b);
	}
}

void	optmize_push_b(t_list **stack_a, t_list **stack_b, t_push set)
{
	while (*stack_a && (*stack_a)->index > ft_lstlast((*stack_a))->index \
							&& (ft_lstlast((*stack_a))->index >= set.init \
							&& ft_lstlast((*stack_a))->index <= set.end))
	{
		if (*stack_b && (*stack_b)->index < (ft_lstlast(*stack_b))->index)
			rrr(stack_a, stack_b);
		else
			rra(stack_a);
	}
	while ((*stack_a) && (*stack_a)->next \
						&& (*stack_a)->index > ((*stack_a)->next)->index \
						&& (((*stack_a)->next)->index >= set.init \
						&& ((*stack_a)->next)->index <= set.end))
	{
		if ((*stack_b) && (*stack_b)->next \
						&& (*stack_b)->index < ((*stack_b)->next)->index)
			ss(stack_a, stack_b);
		else
			sa(stack_a);
	}
}
