/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:06:42 by aben-hss          #+#    #+#             */
/*   Updated: 2023/11/27 03:06:44 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*dst;

	i = 0;
	len = ft_strlen(src);
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	while (i <= len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
