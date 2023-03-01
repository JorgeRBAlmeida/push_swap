/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:29:00 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/01 19:37:08 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_special(char **s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!*s1 && !s2)
		return (NULL);
	i = ft_strlen(*s1);
	j = ft_strlen(s2);
	join = ft_calloc((i + j + 1), sizeof(char));
	if (join == NULL)
		return (NULL);
	ft_strlcat(join, *s1, i + 1);
	ft_strlcat(join, s2, i + j + 1);
	free(*s1);
	return (join);
}

int		is_sorted(t_list **stack_a)
{
	t_list	*first;
	t_list	*backup;

	first = *stack_a;
	backup = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a == NULL)
	{
		*stack_a = backup;
		return (1);
	}
	while (*stack_a && first->index < (*stack_a)->index)
	{
		first = *stack_a;
		*stack_a = (*stack_a)->next;
		if (*stack_a == NULL)
		{
			*stack_a = backup;
			return (1);
		}
	}
	*stack_a = backup;
	return (0);
}

int		is_inverted(t_list *stack_a)
{
	t_list	*first;

	first = stack_a;
	stack_a = stack_a->next;
	if (stack_a == NULL)
		return (1);
	while (stack_a && first->index > stack_a->index)
	{
		first = stack_a;
		stack_a = stack_a->next;
		if (stack_a == NULL)
			return (1);
	}
	return (0);
}
