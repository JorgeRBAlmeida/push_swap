/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:23:48 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/02 03:21:47 by joalmeid         ###   ########.fr       */
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
	while (find_minor_position( *stack_a) != 1 && find_minor_position(*stack_a) <= 3)
		ra(stack_a);
	while (find_minor_position(*stack_a) >= 4)
		rra(stack_a);
	pb(stack_b, stack_a);
	sort_for_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}



/* void	sort_for_rest(t_list **stack_a, t_list **stack_b)
{
	
} */
