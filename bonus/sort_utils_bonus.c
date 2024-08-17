/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <aben-hss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 07:12:39 by aben-hss          #+#    #+#             */
/*   Updated: 2024/07/27 09:46:45 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rank_nodes(t_stack *stack)
{
	int		rank;
	t_stack	*current;
	t_stack	*compare;

	current = stack;
	while (current)
	{
		rank = 0;
		compare = stack;
		while (compare)
		{
			if (compare->num < current->num)
				rank++;
			compare = compare->next;
		}
		current->rank = rank;
		current = current->next;
	}
}

int	check_error(char *str)
{
	char	*clear;

	clear = str;
	while (*str == ' ')
		str++;
	if (!*str)
		return (free(clear), ft_putstr_fd("Error\n", 2), 1);
	while (*str)
	{
		if (!(ft_isdigit(*str) || ft_strchr("+- ", *str)))
			return (free(clear), ft_putstr_fd("Error\n", 2), 1);
		if (ft_strchr("+-", *str) && (!ft_isdigit(*(str + 1))
				|| *(str - 1) != ' '))
			return (free(clear), ft_putstr_fd("Error\n", 2), 1);
		str++;
	}
	return (0);
}

char	*get_chars(char **av)
{
	int		i;
	int		j;
	char	*temp;
	char	*clear;

	i = 0;
	temp = NULL;
	while (av[i])
	{
		j = 0;
		clear = av[i];
		while (clear[j] == ' ')
			j++;
		if (!clear[j])
		{
			free(temp);
			write(2, "Error\n", 6);
			exit(1);
		}
		temp = ft_strjoin(temp, " ");
		temp = ft_strjoin(temp, av[i++]);
	}
	return (temp);
}

int	initialize_stacks(char **av, t_stack **a, t_stack **b)
{
	char	*str;
	char	**nums;

	str = get_chars(av + 1);
	if (check_error(str))
		return (1);
	nums = ft_split(str, ' ');
	check_overflow(nums);
	*a = store_nums(nums);
	if (check_dubs(*a))
	{
		clear_stack(*a);
		write(2, "Error\n", 6);
		return (1);
	}
	*b = NULL;
	return (0);
}
