/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:34:47 by joalmeid          #+#    #+#             */
/*   Updated: 2023/03/01 01:22:28 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	c_incidence(char *t, char c);
static int		is_error(char **arr, size_t *j);
static char		*make_string(char *t, size_t *i, size_t *y);
static int		alloc_arr(char ***arr, char *t, char c, const char *s);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	y;
	size_t	j;
	char	*t;
	char	**arr;

	i = -1;
	y = 0;
	j = 0;
	t = ft_strtrim(s, &c);
	if (!alloc_arr(&arr, t, c, s))
		return (NULL);
	while (++ i <= ft_strlen(t) && c_incidence(t, c) != 0)
	{
		if ((t[i] == c && t[i - 1] != c) || t[i] == '\0')
		{
			arr[j] = make_string(t, &i, &y);
			is_error(arr, &j);
		}
		if (t[i] != c)
			y ++;
	}
	free(t);
	arr[j] = NULL;
	return (arr);
}

static int	alloc_arr(char ***arr, char *t, char c, const char *s)
{
	if (t == NULL || s == NULL)
		return (0);
	*arr = ft_calloc((c_incidence(t, c) + 1), sizeof(char *));
	if (arr == NULL)
	{
		free(t);
		return (0);
	}
	return (1);
}

static size_t	c_incidence(char *t, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(t) == 0)
		return (0);
	while (t[i])
	{
		if (t[i] == c && t[i - 1] != c)
			j ++;
		i ++;
	}
	return (j + 1);
}

static char	*make_string(char *t, size_t *i, size_t *y)
{
	size_t	len;
	size_t	position;
	char	*str;

	position = *i;
	len = *y;
	*i = *i + 1;
	*y = 0;
	str = ft_substr(t, (position - len), len);
	return (str);
}

static int	is_error(char **arr, size_t *j)
{
	if (arr[*j] == NULL)
	{
		while (*j > 0)
		{
			*j = *j - 1;
			free(arr[*j]);
		}
		if (*j == 0 && arr[0] == NULL)
			free(arr);
		return (1);
	}
	else
		*j = *j + 1;
	return (0);
}
