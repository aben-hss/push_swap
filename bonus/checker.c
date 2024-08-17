/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <aben-hss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:49:58 by aben-hss          #+#    #+#             */
/*   Updated: 2024/07/28 04:06:29 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	handle_invalid_instruction(t_stack *a, t_stack *b)
{
	clear_stack(a);
	clear_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	execute_instruction(t_stack **a, t_stack **b, char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		swap_it(a);
	else if (!ft_strcmp(instruction, "sb\n"))
		swap_it(b);
	else if (!ft_strcmp(instruction, "ss\n"))
		(swap_it(a), swap_it(b));
	else if (!ft_strcmp(instruction, "pa\n"))
		push_it(a, b);
	else if (!ft_strcmp(instruction, "pb\n"))
		push_it(b, a);
	else if (!ft_strcmp(instruction, "ra\n"))
		rotate_it(a);
	else if (!ft_strcmp(instruction, "rb\n"))
		rotate_it(b);
	else if (!ft_strcmp(instruction, "rr\n"))
		(rotate_it(a), rotate_it(b));
	else if (!ft_strcmp(instruction, "rra\n"))
		rev_rot_it(a);
	else if (!ft_strcmp(instruction, "rrb\n"))
		rev_rot_it(b);
	else if (!ft_strcmp(instruction, "rrr\n"))
		(rev_rot_it(a), rev_rot_it(b));
	else
		handle_invalid_instruction(*a, *b);
}

int	read_and_execute(t_stack **a, t_stack **b)
{
	char	*instruction;

	while (1)
	{
		instruction = get_next_line(0);
		if (!instruction)
			break ;
		execute_instruction(a, b, instruction);
		free(instruction);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac <= 1)
		return (0);
	if (initialize_stacks(av, &a, &b) != 0)
		return (1);
	read_and_execute(&a, &b);
	if (check_sorted(a) && !b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clear_stack(a);
	clear_stack(b);
	return (0);
}
