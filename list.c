/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:44:10 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/01 11:10:44 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_node_new_content(t_content content)
{
	t_list		*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = malloc(sizeof(t_content));
	if (new_node->content == NULL)
	{
		free(new_node->content);
		return (NULL);
	}
	*(t_content *)(new_node->content) = content;
	new_node->next = NULL;
	return (new_node);
}

void	print_lst(t_list *node, char *name)
{
	t_content	*content;

	if (node == NULL)
		printf("*node == NULL\n");
	if ((node)->content == NULL)
		printf("(*node)->content == NULL\n");
	printf("\n");
	while ((node) != NULL)
	{
		content = (t_content *)(node)->content;
		printf("[%d] %d\n", content->index, content->data);
		node = (node)->next;
	}
	printf("\nstack %s\n", name);
}

void	create_stack_a(t_list **stack_a, char **argv)
{
	int			i;
	int			j;
	t_content	new_content;

	i = 0;
	while (argv[i])
	{
		new_content.index = 0;
		new_content.data = ft_atoi(argv[i]);
		ft_lstadd_back(stack_a, ft_node_new_content(new_content));
		i ++;
	}
	j = i;
	i = 1;
	printf("linhas 67");
	while (j > 1 && i <= j)
	{
		printf("linhas 70");
		put_index_node(stack_a, i);
		printf("linhas 72");
		i ++;
	}
}

void	put_index_node(t_list **stack, int index)
{
	t_content	*minor_content;
	t_content	*tmp;
	t_list		*first;

	printf("linha 80");
	first = *stack;
	tmp = malloc(sizeof(t_content));
	minor_content = malloc(sizeof(t_content));
	//minor_content = find_minor_data(stack);
	if (minor_content == NULL)
		return ;
	minor_content->data = 1;
	minor_content->index = index;
	tmp = (*stack)->content;
	printf("linha 83");
	while (*stack && minor_content != NULL && tmp->data != minor_content->data)
	{
		free(tmp);
		tmp = malloc(sizeof(t_content));
		*stack = (*stack)->next;
		tmp = (*stack)->content;
		printf("tmp content data %d", tmp->data);
	}
	free(tmp);
	if (minor_content != NULL)
	{
		printf("linha 92");
		minor_content->index = index;
		(*stack)->content = minor_content;
	}
	*stack = first;
}

t_content	*find_minor_data(t_list **stack)
{
	t_content	*minor_content;
	t_content	*content2;
	t_list		*first;

	first = *stack;
	minor_content = malloc(sizeof(t_content));
	content2 = malloc(sizeof(t_content));
	minor_content = (*stack)->content;
	// vai passar de ponteiro até encontrar um não setado
	while (*stack && minor_content->index != 0)
	{
		*stack = (*stack)->next;
		minor_content = (*stack)->content;
	}
	while (*stack)
	{
		*stack = (*stack)->next;
		content2 = (*stack)->content;
		if (minor_content->data > content2->data && content2->index == 0)
			minor_content = content2;
	}
	free(content2);
	*stack = first;
	if (minor_content->index != 0)
	{
		free(minor_content);
		return (NULL);
	}
	return (minor_content);
}

void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = NULL;
	while (*stack_a != NULL)
	{
		tmp = (*stack_a)->next;
		free((*stack_a)->content);
		free((*stack_a));
		(*stack_a) = tmp;
	}
	tmp = NULL;
	while (*stack_b != NULL)
	{
		tmp = (*stack_b)->next;
		free((*stack_b)->content);
		free((*stack_b));
		(*stack_b) = tmp;
	}
}
