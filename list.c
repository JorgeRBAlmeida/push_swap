/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:44:10 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/27 17:07:59 by joalmeid         ###   ########.fr       */
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

void	print_lst(t_list *node)
{
	t_content	*content;

	if (node == NULL)
		printf("*node == NULL\n");
	if ((node)->content == NULL)
		printf("(*node)->content == NULL\n");
	while ((node) != NULL)
	{
		content = (t_content *)(node)->content;
		printf("%d\n", content->data);
		node = (node)->next;
	}
}

void	create_stack_a(t_list **node, char **argv)
{
	int			i;
	t_content	new_content;

	i = 0;
	while (argv[i])
	{
		new_content.index = 0;
		new_content.data = ft_atoi(argv[i]);
		ft_lstadd_back(node, ft_node_new_content(new_content));
		i ++;
	}
	
}