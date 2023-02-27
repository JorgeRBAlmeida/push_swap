/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:05:09 by joalmeid          #+#    #+#             */
/*   Updated: 2022/05/25 13:38:54 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;
	size_t	srclen;

	n = dstsize;
	srclen = ft_strlen(src);
	if (n > 0)
	{
		while (*src && (n - 1) > 0)
		{
			n --;
			*dst ++ = *src ++;
		}
	}
	if (dstsize != 0)
		*dst = '\0';
	return (srclen);
}
