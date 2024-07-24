/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <aben-hss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 07:12:00 by aben-hss          #+#    #+#             */
/*   Updated: 2024/07/24 07:41:04 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cs_atoi(char *str, char **free_it)
{
	unsigned long	ret;
	int				sign;

	ret = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + (*str) - '0';
		str++;
		if (ret > 2147483647 && sign == 1)
			return (dealloc(free_it), ft_putstr_fd("Error\n", 2), exit(1), 0);
		if (ret > 2147483648 && sign == -1)
			return (dealloc(free_it), ft_putstr_fd("Error\n", 2), exit(1), 0);
	}
	return ((int)ret * sign);
}

t_stack	*store_nums(char **nums)
{
	t_stack	*head;
	char	**clear;

	clear = nums;
	head = NULL;
	while (*nums)
	{
		add_to_stack(&head, new_node(cs_atoi(*nums, NULL)));
		nums++;
	}
	dealloc(clear);
	return (head);
}

void	check_overflow(char **chars)
{
	int	i;

	i = 0;
	while (chars[i])
		cs_atoi(chars[i++], chars);
}

int	check_dubs(t_stack *a)
{
	t_stack	*temp;
	int		temp_int;

	while (a)
	{
		temp_int = a->num;
		temp = a->next;
		while (temp)
		{
			if (temp_int == temp->num)
				return (1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}

int	check_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->next && stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
