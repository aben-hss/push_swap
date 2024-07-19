/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:57:59 by aben-hss          #+#    #+#             */
/*   Updated: 2023/11/27 02:58:03 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_signed(int n)
{
	return (n < 0);
}

static int	get_len(int num)
{
	int	digit_count;

	digit_count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		digit_count++;
		num = -num;
	}
	while (num > 0)
	{
		num /= 10;
		digit_count++;
	}
	return (digit_count);
}

static void	fill(char *str, int n, int indx)
{
	while (n != 0)
	{
		str[indx] = n % 10 + '0';
		n /= 10;
		indx++;
	}
	str[indx] = '\0';
}

static void	rev_str(char *str, int start, int end)
{
	char	tmp;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		is_negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	is_negative = is_signed(n);
	len = get_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (is_negative)
	{
		str[0] = '-';
		n = -n;
	}
	fill(str, n, is_negative);
	rev_str(str, is_negative, len - 1);
	return (str);
}
