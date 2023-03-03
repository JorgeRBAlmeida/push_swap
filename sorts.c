/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:23:48 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/03 01:35:39 by joalmeid         ###   ########.fr       */
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

/* void	partition(t_list **stack_a, t_list **stack_b, int stack_size, char in)
{
	int		half_stack;
	t_list	*first_major;
	t_list	*first_minor;

	half_stack = stack_size / 2;
	while(*stack_a && (*stack_a)->index < half_stack && in == 'A')
		pb(stack_b, stack_a);
	while(*stack_b && (*stack_b)->index > half_stack && in == 'B')
		pa(stack_a, stack_b);
	if (*stack_a != NULL && in == 'A')
		first_major = *stack_a;
	else if (*stack_b != NULL && in == 'B')
		first_minor = *stack_b;
	else
		return ;
	if (in == 'A')
	{
		if (get_most_minor_half(*stack_a, half_stack) == 1)
		{
			ra(stack_a);
			while (*stack_a && (*stack_a)->index != first_major->index)
			{
				if((*stack_a)->index < half_stack)
					pb(stack_b, stack_a);
				ra(stack_a);
			}
		}
		else if (get_most_minor_half(*stack_a, half_stack) == 2)
		{
			rra(stack_a);
			while (*stack_a && (*stack_a)->index != first_major->index)
			{
				if((*stack_a)->index < half_stack)
					pb(stack_b, stack_a);
				rra(stack_a);
			}
		}
		if (!is_sorted(stack_a) && *stack_b && ft_lstsize(*stack_b) >= 0)
			partition(stack_a, stack_b, stack_size / 2, 'B');
		else if (!is_sorted(stack_a) && *stack_b == NULL)
			partition(stack_a, stack_b, stack_size / 2, 'A');
		else
			return;
	}
	else if (in == 'B')
	{
		if (stack_size == 1)
		{
			pa(stack_a, stack_a);
		}
		rra(stack_b);
		if (get_most_minor_half(*stack_b, half_stack) == 1)
		while (*stack_b && (*stack_b)->index != first_minor->index)
		{
			if((*stack_b)->index > half_stack)
				pb(stack_b, stack_a);
			rra(stack_b);
		}
		else if (get_most_minor_half(*stack_a, half_stack) == 2)
		{
			ra(stack_b);
			while (*stack_b && (*stack_b)->index != first_minor->index)
			{
				if((*stack_b)->index > half_stack)
					pb(stack_b, stack_a);
				ra(stack_b);
			}
		}
		partition(stack_a, stack_b, stack_size / 2, 'A');
	}
} */

int		get_most_minor_half(t_list *stack, int half_stack, int *num_nodes)
{
	int	first_qnt;
	int	second_qnt;
	int	first_half;

	first_qnt = 0;
	second_qnt = 0;
	first_half = half_stack;
	while (stack && first_half)
	{
		if (stack->index <= half_stack)
			first_qnt ++;
		first_half --;
		stack = stack->next;
	}
	second_qnt = half_stack - first_half;
	if (first_qnt > second_qnt)
	{
		*num_nodes = first_qnt;
		return (1);
	}
	*num_nodes = second_qnt;
	return (2);
}

void	push_minor_b(t_list **stack_a, t_list **stack_b, t_push set)
{
	int	minors;

	minors = set.minor_qnt;
	while (*stack_a != NULL && minors > 0)
	{
		if ((*stack_a)->index <= set.size_half)
		{
			if ((*stack_a)->index > (ft_lstlast(*stack_a))->index)
				rra(stack_a);
			if ((*stack_a)->index > ((*stack_a)->next)->index)
				sa(stack_a);
			pb(stack_b, stack_a);
			minors --;
		}
		if (set.half == 1)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	partition(t_list **stack_a, t_list **stack_b, int stack_size)
{
	t_push	set;

	set.minor_qnt = 0;
	set.size_half = stack_size;
	set.half = get_most_minor_half(*stack_a, set.size_half / 2, &set.minor_qnt);
	push_minor_b(stack_a, stack_b, set);
	if (stack_size >= 5)
	{
		printf("stack_size=|%d|\n", stack_size);
		partition(stack_a, stack_b, stack_size / 2);
	}
}
