/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:23:48 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/06 20:25:02 by joalmeid         ###   ########.fr       */
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
		big_sort(stack_a, stack_b, stack_size);
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

	position = 0;
	while (node && node->index != index)
	{
		node = node->next;
		position ++;
	}
	position ++;
	if (index != ft_lstlast(node)->index)
		position = 0;
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
	int	first_qnt;
	int	second_qnt;
	int	first_p;
	t_push	set;

	first_qnt = 0;
	second_qnt = 0;
	first_p = ft_lstsize(stack) / 2 + ft_lstsize(stack) % 2;
	set.init = init;
	set.end = end;
	set.top_or_botton = 1;
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
			optmize_b(stack_a, stack_b, set, 0);
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
	while (*stack_a && (*stack_a)->index > ft_lstlast((*stack_a))->index \
							&& (ft_lstlast((*stack_a))->index >= set.init \
							&& ft_lstlast((*stack_a))->index <= set.end))
	{
		if (*stack_b && (*stack_b)->index < (ft_lstlast(*stack_b))->index)
			rrr(stack_a, stack_b);
		else
			rra(stack_a);
	}
	while ((*stack_a) && (*stack_a)->next 
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

int	optmize_b(t_list **stack_a, t_list **stack_b, t_push set, int revert_rb)
{
	if (*stack_b && (*stack_b)->index < ft_lstlast((*stack_b))->index \
							&& (ft_lstlast((*stack_b))->index >= set.init \
							&& ft_lstlast((*stack_b))->index <= set.end))
	{
		if (*stack_a && (*stack_a)->index > ft_lstlast((*stack_a))->index)
			rrr(stack_a, stack_b);
	}
	if (revert_rb)
		return (-1);
	else
		return (0);
	while (*stack_b && (*stack_b)->next \
					&& (*stack_b)->index == ((*stack_b)->next)->index + 1 \
					&& (((*stack_b)->next)->index >= set.init \
					&& ((*stack_b)->next)->index <= set.end))
	{
		if (*stack_a && (*stack_a)->next && (*stack_a)->index \
												> ((*stack_a)->next)->index)
			ss(stack_a, stack_b);
		else
			sb(stack_b);
	}
}



int	rrb_till_major_b(t_list **stack_b, int major_b, int revert_rb)
{
	
	if (*stack_b && find_stack_position(major_b, *stack_b) \
						>= (ft_lstsize(*stack_b) - revert_rb))
	{
		while (*stack_b && (*stack_b)->index != major_b && revert_rb >= 0)
		{
			revert_rb --;
			rrb(stack_b);
		}
		if (revert_rb < 0)
			revert_rb = 0;
	}
	return (revert_rb);
}

int	not_major_action(t_list **stack_a, t_list **stack_b, int stack_size)
{
	int revert_rb;

	revert_rb = 0;
	if ((ft_lstlast(*stack_a)->index == stack_size || \
		(*stack_b)->index == ft_lstlast(*stack_a)->index + 1))
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else
	{
		rb(stack_b);
		revert_rb ++;
	}
	return (revert_rb);
}

/* void	push_back_a(t_list **stack_a, t_list **stack_b, t_push set, \
															int stack_size)
{
	int	major_b;
	int	revert_rb;

	revert_rb = 0;
	major_b = stack_size;
	set.init = 1;
	while (*stack_b && major_b)
	{
		if (*stack_b && (*stack_b)->index == major_b)
		{
			pa(stack_a, stack_b);
			major_b --;
			revert_rb = rrb_till_major_b(stack_b, major_b, revert_rb);
		}
		if (*stack_a && major_b < stack_size \
								&& ft_lstlast(*stack_a)->index == major_b)
		{
			while (*stack_a && ft_lstlast(*stack_a)->index != stack_size)
			{
				rra(stack_a);
				major_b --;
			}
			revert_rb = rrb_till_major_b(stack_b, major_b, revert_rb);
		}
		else if (*stack_b && (*stack_b)->index != major_b)
			not_major_action(stack_a, stack_b, stack_size);
	}
} */

void	push_back_a(t_list **stack_a, t_list **stack_b, t_push set, \
															int stack_size)
{
	int	major_b;

	major_b = stack_size;
	while (*stack_b && major_b)
	{
		set.init = major_b;
		set.end = major_b;
		if (find_stack_position(major_b, stack_b))
		{
			set = set_push_b_stategy(*stack_a, set.init, set.end);
			if (set.top_or_botton == 1)
				
		}
		
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b, int stack_size)
{
	t_push	set;

	set.init = 1;
	set.end = 15;
	while (*stack_a && stack_size > 400)
	{
		set.end += 33;
		set = set_push_b_stategy(*stack_a, set.init, set.end);
		push_range_b(stack_a, stack_b, set);
	}
	while (*stack_a && stack_size < 400)
	{
		set.end += 15;
		set = set_push_b_stategy(*stack_a, set.init, set.end);
		push_range_b(stack_a, stack_b, set);
	}
	push_back_a(stack_a, stack_b, set, stack_size);
}
