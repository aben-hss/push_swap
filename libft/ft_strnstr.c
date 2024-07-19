/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:09:28 by aben-hss          #+#    #+#             */
/*   Updated: 2023/11/27 03:09:30 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	i = 0;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *) haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0] && i + needle_len <= len)
		{
			if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
				return ((char *) &haystack[i]);
		}
		i++;
	}
	return (NULL);
}
