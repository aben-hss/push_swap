/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <aben-hss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 07:11:22 by aben-hss          #+#    #+#             */
/*   Updated: 2024/07/24 09:45:47 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	j = 0;
	temp = NULL;
	while (av[i])
	{
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

void	sort_stack(t_stack **a, t_stack **b, size_t stack_size)
{
	if (stack_size == 2)
		swap_it(a, 'a');
	else if (stack_size == 3)
		sort_three(a);
	else if (stack_size == 4)
		sort_four(a, b);
	else if (stack_size == 5)
		sort_five(a, b);
	else
		sort_all(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	size_t	stack_size;

	a = NULL;
	b = NULL;
	if (ac <= 1)
		return (0);
	if (initialize_stacks(av, &a, &b) != 0)
		return (1);
	if (!check_sorted(a))
	{
		stack_size = get_stack_size(a);
		rank_nodes(a);
		sort_stack(&a, &b, stack_size);
	}
	clear_stack(a);
	return (0);
}
