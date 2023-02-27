/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:19:45 by joalmeid          #+#    #+#             */
/*   Updated: 2022/05/25 17:33:24 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && *s2 && (*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}
	if (n <= 0)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
