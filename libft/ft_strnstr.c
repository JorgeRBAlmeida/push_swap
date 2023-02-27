/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:19:47 by joalmeid          #+#    #+#             */
/*   Updated: 2022/06/06 12:22:05 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	len_needle;

	index = 0;
	len_needle = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	if (needle == haystack)
		return ((char *)haystack);
	while ((index <= (len - len_needle)) && (haystack[index] != '\0'))
	{
		if (haystack[index] == needle[0])
		{
			if (!ft_strncmp(haystack + index, needle + 0, len_needle))
				return ((char *)&haystack[index]);
		}
		index ++;
	}
	return (NULL);
}
