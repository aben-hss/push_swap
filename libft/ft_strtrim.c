/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:09:59 by aben-hss          #+#    #+#             */
/*   Updated: 2023/11/27 03:10:02 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dst[i] = '\0';
		++i;
	}
	return (dst);
}

static int	is_in_set(const char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static char	*create_empty_str(void)
{
	char	*empty_str;

	empty_str = (char *)malloc(1);
	if (!empty_str)
		return (NULL);
	if (empty_str)
		empty_str[0] = '\0';
	return (empty_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	size_t	new_len;
	char	*new_str;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	if (len == 0)
		return (create_empty_str());
	start = 0;
	while (start < len && is_in_set(s1[start], set))
		start++;
	end = len - 1;
	while (end > start && is_in_set(s1[end], set))
		end--;
	new_len = end - start + 1;
	new_str = (char *)malloc(new_len + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strncpy(new_str, s1 + start, new_len);
	new_str[new_len] = '\0';
	return (new_str);
}
