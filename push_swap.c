/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 00:33:40 by joalmeid          #+#    #+#             */
/*   Updated: 2023/02/27 17:29:24 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**new_argv;
	t_list	*stack_a;
	t_list	*tmp;
	//t_list	stack_b;

	stack_a = NULL;
	tmp = NULL;
	if (argc > 1)
	{
		new_argv = remove_space_argv(argv);
		if (!validate_args(new_argv))
			ft_putstr_fd("Error\n", 1);
		else
		{
			create_stack_a(&stack_a, new_argv);
			print_lst(stack_a);
		}
		free_new_argv(new_argv);
	}
	while (stack_a != NULL)
	{
		tmp = stack_a->next;
		free(stack_a->content);
		free(stack_a);
		stack_a = tmp;
	}
	return (0);
}

void	free_new_argv(char **new_argv)
{
	int	i;

	i = 0;
	while (new_argv[i])
	{
		free(new_argv[i]);
		i ++;
	}
	free(new_argv);
	new_argv = NULL;
}

char	**remove_space_argv(char **argv)
{
	int		i;
	char	*tmp;
	char	*acc;
	char	**result;

	i = 1;
	acc = malloc(sizeof(char)*ft_strlen(argv[i]));
	while (argv[i])
	{
		tmp = ft_strjoin(argv[i], " ");
		acc =  ft_strjoin_special(&acc, tmp);
		free(tmp);
		i ++;
	}
	result = ft_split(acc, ' ');
	free(acc);
	return (result);
}

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
	
	i= 0;
	j = 0;
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
