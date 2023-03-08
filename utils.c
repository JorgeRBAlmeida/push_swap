/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:29:00 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/08 15:14:13 by joalmeid         ###   ########.fr       */
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

int	is_sorted(t_list **stack_a)
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

int	is_inverted(t_list *stack_a)
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

void	print_action(char *act)
{
	static char	lst[5];

	if (lst[0] != '\0' && ft_strncmp(act, "\0", 1))
	{
		if ((!ft_strncmp(lst, "sa\n", 3) && !ft_strncmp(act, "sb\n", 3))
			|| (!ft_strncmp(lst, "sb\n", 3) && !ft_strncmp(act, "sa\n", 3)))
			ft_strlcpy(lst, "ss\n", 4);
		else if ((!ft_strncmp(lst, "ra\n", 3) && !ft_strncmp(act, "rb\n", 3))
			|| (!ft_strncmp(lst, "rb\n", 3) && !ft_strncmp(act, "ra\n", 3)))
			ft_strlcpy(lst, "rr\n", 4);
		else if ((!ft_strncmp(lst, "rra\n", 4) && !ft_strncmp(act, "rrb\n", 4))
			|| (!ft_strncmp(lst, "rrb\n", 4) && !ft_strncmp(act, "rra\n", 4)))
			ft_strlcpy(lst, "rrr\n", 5);
		else
		{
			ft_putstr_fd(lst, 1);
			ft_strlcpy(lst, act, ft_strlen(act) + 1);
		}
	}
	else
		ft_strlcpy(lst, act, ft_strlen(act) + 1);
}
