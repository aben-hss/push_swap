/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:09:46 by aben-hss          #+#    #+#             */
/*   Updated: 2023/11/27 03:09:47 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occ;

	last_occ = NULL;
	while (*s != '\0')
	{
		if (*s == (char) c)
			last_occ = s;
		s++;
	}
	if (*s == (char)c)
		last_occ = s;
	return ((char *) last_occ);
}
