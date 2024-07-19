/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:07:51 by aben-hss          #+#    #+#             */
/*   Updated: 2023/11/27 03:07:52 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *str, size_t max_len)
{
	size_t	len;

	len = 0;
	while (len < max_len && str[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		dst_len;

	d = dst;
	s = src;
	dst_len = ft_strnlen(dst, dstsize);
	if (dstsize == 0)
		return (dst_len + ft_strlen(src));
	while (*d && dstsize > 0)
	{
		d++;
		dstsize--;
	}
	while (*s && dstsize > 1)
	{
		*d++ = *s++;
		dstsize--;
	}
	if (dstsize > 0)
		*d = '\0';
	return (dst_len + ft_strlen(src));
}
