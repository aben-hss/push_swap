/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <aben-hss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 07:12:48 by aben-hss          #+#    #+#             */
/*   Updated: 2024/08/23 13:32:03 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to push elements from stack A to stack B
void	push_to_b(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = get_stack_size(*a);
	j = size / 15;
	if (size <= 100)
		j = size / 7; // Adjust chunk size for smaller stacks
	while (*a)
	{
		if ((*a)->rank <= i)
		{
			push_it(b, a, 'b');  // Push smaller elements directly to B
			i++;
		}
		else if ((*a)->rank <= i + j)
		{
			push_it(b, a, 'b'); // Push elements from the next chunk to B
			rotate_it(b, 'b');  // Rotate B to keep larger elements at the bottom
			i++;
		}
		else
			rotate_it(a, 'a'); // Rotate A to find next suitable element
	}
}

// Function to find the index of an element with a specific rank in the stack
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
	return (-1); // Return -1 if rank not found
}

// Function to push elements from stack B back to stack A in sorted order
void	push_to_a(t_stack **a, t_stack **b)
{
	int	top_rank_index;
	int	size;

	while (*b)
	{
		size = get_stack_size(*b);
		top_rank_index = get_index(*b, size - 1); // Find index of highest ranked element
		if (top_rank_index <= size / 2)
		{
			// If highest element is in the top half, rotate until it's at the top
			while ((*b)->rank != size - 1)
				rotate_it(b, 'b');
		}
		else
		{
			// If highest element is in the bottom half, reverse rotate until it's at the top
			while ((*b)->rank != size - 1)
				rev_rot_it(b, 'b');
		}
		push_it(a, b, 'a'); // Push the highest element to A
	}
}

// Main sorting function
void	sort_all(t_stack **a, t_stack **b)
{
	push_to_b(a, b); // First, push elements from A to B in a strategic manner
	push_to_a(a, b); // Then, push elements back from B to A in sorted order
}
