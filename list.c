/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:44:10 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/01 15:16:26 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_node_new_data(int data, int index)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

void	print_lst(t_list *lst, char *name)
{
	if (lst == NULL)
		printf("*lst == NULL\n");
	printf("\n");
	while (lst)
	{
		printf("[%d] %d\n", lst->index, lst->data);
		lst = lst->next;
	}
	printf("\nstack %s\n", name);
}

void	create_stack_a(t_list **stack_a, char **argv)
{
	int		i;
	int		j;
	t_list	*new_node;

	i = 0;
	new_node = NULL;
	while (argv[i])
	{
		new_node = ft_node_new_data(ft_atoi(argv[i]), 0);
		ft_lstadd_back(stack_a, new_node);
		i ++;
	}
	j = i;
	i = 1;
	while (j > 1 && i <= j)
	{
		put_index_node(stack_a, i);
		i ++;
	}
}

void	put_index_node(t_list **stack, int index)
{
	t_list	*first;
	int		minor_data;

	first = *stack;
	minor_data = find_minor_data(stack);
	//minor_data = 12;
	while (*stack && (minor_data != (*stack)->data))
	{
		*stack = (*stack)->next;
	}
	(*stack)->index = index;
	*stack = first;
}

int	find_minor_data(t_list **stack)
{
	t_list	*first;
	int		minor_data;

	first = *stack;
	minor_data = first->data;
	while (*stack != NULL && (*stack)->index != 0)
		*stack = (*stack)->next;
	if (*stack == NULL)
		return (-1);
	minor_data = (*stack)->data;
	while (*stack != NULL)
	{
		if (minor_data > (*stack)->data && (*stack)->index == 0)
			minor_data = (*stack)->data;
		*stack = (*stack)->next;
	}
	*stack = first;
	return (minor_data);
}

void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = NULL;
	while (*stack_a != NULL)
	{
		tmp = (*stack_a)->next;
		free((*stack_a));
		(*stack_a) = tmp;
	}
	tmp = NULL;
	while (*stack_b != NULL)
	{
		tmp = (*stack_b)->next;
		free((*stack_b));
		(*stack_b) = tmp;
	}
}
