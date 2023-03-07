/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:32:36 by gcorreia          #+#    #+#             */
/*   Updated: 2022/09/23 17:23:07 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	struct s_list	*ptr;

	if (*lst == NULL)
		return ;
	ptr = *lst;
	while (ptr)
	{
		del(ptr->content);
		ptr = ptr->next;
		free(*lst);
		*lst = ptr;
	}
	*lst = NULL;
}
