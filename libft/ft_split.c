/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:06:12 by aben-hss          #+#    #+#             */
/*   Updated: 2023/11/27 03:06:13 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	substr_counter(char const *s, char c)
{
	size_t		num_of_substrs;
	char const	*ptr;

	ptr = s;
	num_of_substrs = 0;
	while (*ptr)
	{
		while (*ptr == c && *ptr)
			ptr++;
		if (*ptr)
			num_of_substrs++;
		while (*ptr != c && *ptr)
			ptr++;
	}
	return (num_of_substrs);
}

void	dealloc(char **s)
{
	size_t	i;

	if(!s)
		return ;
	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free (s);
}

static char	*alloc(const char *str, char c, int *i)
{
	char	*ret;
	size_t	size;

	ret = NULL;
	size = 0;
	while (str [*i] == c && str[*i])
		*i += 1;
	while (str[size + *i] != c && str[size + *i])
		size++;
	ret = ft_substr(str, *i, size);
	if (!ret)
		return (NULL);
	*i += size;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		n;
	int		sub_count;
	int		i;

	i = 0;
	n = 0;
	if (!s)
		return (NULL);
	sub_count = substr_counter(s, c);
	ret = (char **)malloc(sizeof(char *) * (sub_count + 1));
	if (!ret)
		return (NULL);
	while (n < sub_count && *s)
	{
		ret[n] = alloc(s, c, &i);
		if (!ret[n])
		{
			dealloc(ret);
			free((char*)s);
			return (NULL);
		}
		n++;
	}
	ret[n] = NULL;
	free((char*)s);
	return (ret);
}
