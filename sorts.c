/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:23:48 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/03 22:09:13 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;
	//t_list	*first;

	//first = *stack_a;
	stack_size = ft_lstsize(*stack_a);
	if (is_sorted(stack_a))
		return ;
	else if (stack_size == 2)
		sa(stack_a);
	else if (is_inverted((*stack_a)))
		uninvert_stack(stack_a, stack_b, stack_size);
	else if (stack_size == 3)
		sort_for_3(stack_a);
	else if (stack_size == 4)
		sort_for_4(stack_a, stack_b);
	else if (stack_size == 5)
		sort_for_5(stack_a, stack_b);
	else
		partition(stack_a, stack_b, stack_size);
	/* if (!is_sorted(stack_a))
		sort_stack_a(stack_a, stack_b); */
}

void	uninvert_stack(t_list **stack_a, t_list **stack_b, int stack_size)
{
	t_list	*last;
	
	last = ft_lstlast(*stack_a);
	if (stack_size == 3)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else
	{
		while ((((*stack_a)->next)->next)->next != NULL)
		{
			rra(stack_a);
			pb(stack_b, stack_a);
		}
		sa(stack_a);
		rra(stack_a);
		while (*stack_b)
			pa(stack_a, stack_b);
	}
	*stack_a = last;
}

int	find_stack_position(int index, t_list *node)
{
	int	position;

	position = 1;
	while (node && node->index != index)
	{
		node = node->next;
		position ++;
	}
	return (position);
}

int	find_minor_position(t_list *node)
{
	int	position;
	int	minor;
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

void	sort_for_3(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->index;
	second = ((*stack_a)->next)->index;
	third = (((*stack_a)->next)->next)->index;
	if (first < second)
	{
		if (first < third && second > third)
		{
			sa(stack_a);
			ra(stack_a);
		}
		else
			rra(stack_a);
	}
	else if (first > second && second < third)
	{
		if (first > third)
			ra(stack_a);
		else
			sa(stack_a);
	}
	else
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
	sort_for_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_for_5(t_list **stack_a, t_list **stack_b)
{
	while (find_minor_position( *stack_a) != 1 \
				&& find_minor_position(*stack_a) <= 3)
		ra(stack_a);
	while (find_minor_position(*stack_a) >= 4)
		rra(stack_a);
	pb(stack_b, stack_a);
	sort_for_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

t_push	set_push_b_stategy(t_list *stack, int init, int end)
{
	int	size;
	int	first_qnt;
	int	second_qnt;
	int	first_half;
	t_push	set;

	size = ft_lstsize(stack);
	first_qnt = 0;
	second_qnt = 0;
	first_half = size / 2 + size % 2;
	set.init = init;
	set.end = end;
	set.top_or_botton = 1;
	while (stack)
	{
		if (stack->index >= init && stack->index <= end && first_half > 0)
			first_qnt ++;
		else if (stack->index >= init && stack->index <= end && first_half <= 0)
			second_qnt ++;
		first_half --;
		stack = stack->next;
	}
	set.qnt = first_qnt + second_qnt;
	if (first_qnt < second_qnt)
		set.top_or_botton = 2;
	return (set);
}

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
			optmize_b(stack_a, stack_b, set);
			ranged --;
		}
		else if (*stack_a && set.top_or_botton == 1)
			ra(stack_a);
		else if (*stack_a && set.top_or_botton == 2)
			rra(stack_a);
	}
}

void	optmize_push_b(t_list **stack_a, t_list **stack_b, t_push set)
{
	if (*stack_a && (*stack_a)->index > (ft_lstlast(*stack_a))->index \
		&& ((ft_lstlast(*stack_a))->index >= set.init && (ft_lstlast(*stack_a))->index <= set.end))
	{
		if (*stack_b && (*stack_b)->index < (ft_lstlast(*stack_b))->index)
			rrr(stack_a, stack_b);
		else
			rra(stack_a);
	}
	else if ((*stack_a) && (*stack_a)->next && (*stack_a)->index > ((*stack_a)->next)->index \
	&& (((*stack_a)->next)->index >= set.init && ((*stack_a)->next)->index <= set.end))
	{
		if ((*stack_b) && (*stack_b)->next && (*stack_b)->index < ((*stack_b)->next)->index)
			ss(stack_a, stack_b);
		else
			sa(stack_a);
	}
}

void	optmize_b(t_list **stack_a, t_list **stack_b, t_push set)
{
	if (*stack_b && (*stack_b)->index < (ft_lstlast(*stack_b))->index \
		&& ((ft_lstlast(*stack_b))->index <= set.init && (ft_lstlast(*stack_b))->index <= set.end))
	{
		if (*stack_a && (*stack_a)->index > (ft_lstlast(*stack_a))->index)
			rrr(stack_a, stack_b);
		else
			rrb(stack_b);
	}
	if ((*stack_b)->next && (*stack_b)->index < ((*stack_b)->next)->index \
	&& (((*stack_b)->next)->index >= set.init && ((*stack_b)->next)->index <= set.end))
	{
		if ((*stack_a)->next && (*stack_a)->index > ((*stack_a)->next)->index)
			ss(stack_a, stack_b);
		else
			sb(stack_b);
	}
}

void	partition(t_list **stack_a, t_list **stack_b, int stack_size)
{
	t_push	set;

	set.init = 1;
	set.end = 14;
	while (*stack_a && stack_size > 400)
	{
		set = set_push_b_stategy(*stack_a, set.init, set.end);
		push_range_b(stack_a, stack_b, set);
		set.end += 32;
	}
	while (*stack_a && stack_size < 400)
	{
		set = set_push_b_stategy(*stack_a, set.init, set.end);
		push_range_b(stack_a, stack_b, set);
		set.end += 22;
	}
}
