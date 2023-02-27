/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:30:39 by joalmeid          #+#    #+#             */
/*   Updated: 2022/06/06 12:12:48 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cpy;
	size_t	size;

	size = ft_strlen(str) + 1;
	cpy = ft_calloc(size, sizeof(*cpy));
	if (cpy == NULL)
		return (NULL);
	cpy = ft_memcpy(cpy, str, size);
	return (cpy);
}
