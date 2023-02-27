/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 10:57:58 by joalmeid          #+#    #+#             */
/*   Updated: 2022/06/02 11:43:21 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*str;

	index = 0;
	if (!s)
		return (NULL);
	str = ft_calloc((ft_strlen(s) + 1), sizeof(*str));
	if (str == NULL || f == NULL)
		return (NULL);
	while (s[index])
	{
		str[index] = (*f)(index, s[index]);
		index ++;
	}
	str[index] = '\0';
	return (str);
}
