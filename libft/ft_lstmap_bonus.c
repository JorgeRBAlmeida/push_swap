/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 01:20:18 by joalmeid          #+#    #+#             */
/*   Updated: 2022/06/06 11:25:59 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*node;

	first = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
			ft_lstclear(&first, del);
		ft_lstadd_back(&first, node);
		node->next = NULL;
		lst = lst->next;
	}
	return (first);
}
