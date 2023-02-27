/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:47:17 by joalmeid          #+#    #+#             */
/*   Updated: 2022/05/30 16:31:23 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	front_trim(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	offset;
	size_t	j;
	size_t	len_front_trim;
	char	*trimmed;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	offset = front_trim(s1, set);
	len_front_trim = ft_strlen(s1 + offset);
	while (len_front_trim > 0)
	{
		j = 0;
		while (set[j] && s1[len_front_trim + offset - 1] != set[j])
			j ++;
		if (set[j] == '\0')
			break ;
		len_front_trim --;
	}
	trimmed = ft_substr(s1, offset, len_front_trim);
	return (trimmed);
}

static size_t	front_trim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j] && s1[i] != set[j])
			j ++;
		if (set[j] == '\0')
			break ;
		i ++;
	}
	return (i);
}
