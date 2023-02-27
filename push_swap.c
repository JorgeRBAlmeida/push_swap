/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 00:33:40 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/26 23:56:30 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_arg_number(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (i == 0 && str[i] == '-')
			i ++;
		if (!ft_isdigit(str[i]))
			return (0);
		i ++;
	}
	return (1);
}

int	validate_args(char **argv)
{
	int	i;
	int	j;
	
	i= 1;
	j = 1;
	while (argv[i])
	{
		if (!is_arg_number(argv[i]) ||
			((ft_atoi(argv[i]) > INT_MAX) || \
				( ft_atoi(argv[i]) < INT_MIN)))
			return (0);
		j = i - 1;
		while (i > 1 && j >= 1)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j --;
		}
		i ++;
	}
	return (1);
}

t_list	*ft_node_new_content(t_content content)
{
	t_list		*new_node;
	t_content	test;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = malloc(sizeof(t_content));
	if (new_node->content == NULL)
	{
		free(new_node);
		return (NULL);
	}
	*(t_content *)(new_node->content) = content;
	test = *(t_content *)(new_node->content);
	new_node->next = NULL;
	printf("new_node->content= %d\n", test.data);
	return (new_node);
}

void	print_lst(t_list **node)
{
	t_content	*content;

	if (*node == NULL)
	{
		printf("(*node)->content == NULL\n");
	}
	if (*node == NULL || (*node)->content == NULL)
	{
		printf("(*node)->content == NULL\n");
	}
	content = (t_content *)(*node)->content;
	printf("%d\n", content->data);
	/* while (node->next != NULL)
	{
		content = (t_content *)(node->content);
		printf("%d\n", content->data);
		node =node->next;
	} */
}

int node_contains(t_list *node)
{
    while (node)
    {
        if (node->content)
        {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void	create_stack_a(t_list **node, char **argv)
{
	int			i;
	t_content	new_content;
	t_list		*tmp;

	tmp = *node;
	i = 1;
	//new_content = malloc(sizeof(t_content));
	while (argv[i])
	{
		new_content.index = 0;
		new_content.data = ft_atoi(argv[i]);
		ft_lstadd_back(node, ft_lstnew(&new_content));
		i ++;
	}
	*node = tmp;
	//free(new_content);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	//t_list	stack_b;

	//stack_b = NULL;
	stack_a = malloc(sizeof(t_list));
	if (stack_a == NULL)
		return (0);
	if (argc > 1)
	{
		if (!validate_args(argv))
			ft_putstr_fd("Error\n", 1);
		else
			create_stack_a(&stack_a, argv);
		print_lst(&stack_a);
	}
	free(stack_a);
		return (0);
}
