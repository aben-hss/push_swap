/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:10:13 by aben-hss          #+#    #+#             */
/*   Updated: 2023/11/27 03:10:15 by aben-hss         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*sub_str;
	char	*empty_str;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (len == 0 || start >= s_len)
	{
		empty_str = (char *)malloc(1);
		if (!empty_str)
			return (NULL);
		if (empty_str)
			empty_str[0] = '\0';
		return (empty_str);
	}
	if (len > s_len - start)
		len = s_len - start;
	sub_str = (char *)malloc(len + 1);
	if (!sub_str)
		return (NULL);
	ft_strncpy(sub_str, s + start, len);
	sub_str[len] = '\0';
	return (sub_str);
}
