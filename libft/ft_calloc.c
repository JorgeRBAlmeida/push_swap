/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:44:53 by joalmeid          #+#    #+#             */
/*   Updated: 2022/06/01 10:17:10 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*buffer;
	int		total;

	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	total = num * size;
	buffer = malloc(total);
	if (buffer == NULL)
		return (NULL);
	ft_bzero(buffer, total);
	return (buffer);
}
