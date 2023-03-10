/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:42:24 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/10 08:25:00 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_trimmed_argv(char **trimmed_argv)
{
	int	i;

	i = 0;
	while (trimmed_argv[i])
	{
		free(trimmed_argv[i]);
		i ++;
	}
	free(trimmed_argv);
	trimmed_argv = NULL;
}

char	**remove_space_argv(char **argv)
{
	int		i;
	char	*tmp;
	char	*acc;
	char	**result;

	i = 1;
	acc = malloc(sizeof(char) * ft_strlen(argv[i]));
	while (argv[i])
	{
		tmp = ft_strjoin(argv[i], " ");
		acc = ft_strjoin_special(&acc, tmp);
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
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
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

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (!is_arg_number(argv[i]) \
			|| ((ft_atoi(argv[i]) > INT_MAX) \
			|| (ft_atoi(argv[i]) < INT_MIN)))
			return (0);
		j = i - 1;
		while (i >= 1 && j >= 0)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j --;
		}
		i ++;
	}
	return (1);
}
