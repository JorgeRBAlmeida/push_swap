/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:37:09 by joalmeid          #+#    #+#             */
/*   Updated: 2022/06/06 12:12:27 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t n)
{
	const unsigned char	*s1 = b1;
	const unsigned char	*s2 = b2;

	if (s1 == s2)
		return (0);
	while (n && *s1 == *s2)
	{
		++ s1;
		++ s2;
		-- n;
	}
	if (n == 0)
		return (0);
	else
		return (*s1 - *s2);
}
