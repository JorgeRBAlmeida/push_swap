/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:22:48 by joalmeid          #+#    #+#             */
/*   Updated: 2022/05/26 12:50:55 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	join = ft_calloc((i + j + 1), sizeof(*join));
	if (join == NULL)
		return (NULL);
	ft_strlcat(join, s1, i + 1);
	ft_strlcat(join, s2, i + j + 1);
	return (join);
}
