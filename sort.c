/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <aben-hss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 07:12:48 by aben-hss          #+#    #+#             */
/*   Updated: 2024/07/24 07:12:51 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = get_stack_size(*a);
	j = size / 15;
	if (size <= 100)
		j = size / 7;
	while (*a)
	{
		if ((*a)->rank <= i)
		{
			push_it(b, a, 'b');
			i++;
		}
		else if ((*a)->rank <= i + j)
		{
			push_it(b, a, 'b');
			rotate_it(b, 'b');
			i++;
		}
		else
			rotate_it(a, 'a');
	}
}

int	get_index(t_stack *stack, int rank)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->rank == rank)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	int	top_rank_index;
	int	size;

	while (*b)
	{
		size = get_stack_size(*b);
		top_rank_index = get_index(*b, size - 1);
		if (top_rank_index <= size / 2)
		{
			while ((*b)->rank != size - 1)
				rotate_it(b, 'b');
		}
		else
		{
			while ((*b)->rank != size - 1)
				rev_rot_it(b, 'b');
		}
		push_it(a, b, 'a');
	}
}

void	sort_all(t_stack **a, t_stack **b)
{
	push_to_b(a, b);
	push_to_a(a, b);
}
