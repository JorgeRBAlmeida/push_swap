/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:00:12 by joalmeid          #+#    #+#             */
/*   Updated: 2022/05/29 14:51:31 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (n == 0)
	{
		return (dst);
	}
	if (d < s)
		return (ft_memcpy(dst, src, n));
	if (d > s)
	{
		while (n > 0)
		{
		d[n -1] = s[n - 1];
		-- n;
		}
	}
	return (dst);
}
