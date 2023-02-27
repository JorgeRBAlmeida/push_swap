/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:37:00 by joalmeid          #+#    #+#             */
/*   Updated: 2022/06/06 12:11:04 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	found;

	found = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			found ++;
		s ++;
	}
	if ((*s == '\0') && (*s == (char)c))
		return ((char *) s);
	if (!found)
		return (0);
	while (*s != (char) c)
		s --;
	return ((char *) s);
}
