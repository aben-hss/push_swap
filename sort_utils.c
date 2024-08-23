/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <aben-hss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 07:12:39 by aben-hss          #+#    #+#             */
/*   Updated: 2024/08/23 13:23:21 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Assign ranks to nodes based on their relative values
 *
 * This function iterates through the stack and assigns a rank to each node.
 * The rank represents how many nodes have a smaller value than the current node.
 *
 * @param stack: Pointer to the head of the stack
 */
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

/* Sort a stack of three elements
 *
 * This function sorts a stack of exactly three elements using the minimum
 * number of operations. It covers all possible permutations of three elements.
 *
 * @param a: Pointer to the stack to be sorted
 */
void	sort_three(t_stack **a)
{
	int	first;
	int	sec_small;
	int	third;

	first = (*a)->num;
	sec_small = (*a)->next->num;
	third = (*a)->next->next->num;
	if (first > sec_small && sec_small < third && first < third)
		swap_it(a, 'a');
	else if (first > sec_small && sec_small > third)
	{
		swap_it(a, 'a');
		rev_rot_it(a, 'a');
	}
	else if (first > sec_small && sec_small < third && first > third)
		rotate_it(a, 'a');
	else if (first < sec_small && sec_small > third && first < third)
	{
		swap_it(a, 'a');
		rotate_it(a, 'a');
	}
	else if (first < sec_small && sec_small > third && first > third)
		rev_rot_it(a, 'a');
}

/* Sort a stack of four elements
 *
 * This function sorts a stack of exactly four elements. It finds the smallest
 * element, moves it to the top, pushes it to stack B, sorts the remaining three
 * elements, and then pushes the smallest element back to stack A.
 *
 * @param a: Pointer to stack A
 * @param b: Pointer to stack B
 */
void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		smallest;

	current = *a;
	while (current)
	{
		if (current->rank == 0)
			smallest = current->num;
		current = current->next;
	}
	while ((*a)->num != smallest)
	{
		if ((*a)->next->num == smallest || (*a)->next->next->num == smallest)
			rotate_it(a, 'a');
		else
			rev_rot_it(a, 'a');
	}
	push_it(b, a, 'b');
	sort_three(a);
	push_it(a, b, 'a');
}

/* Helper function to push the two smallest elements to stack B
 *
 * This function finds and pushes the two smallest elements from stack A to stack B.
 *
 * @param a: Pointer to stack A
 * @param b: Pointer to stack B
 * @param small: The value of the smallest element
 * @param sec_small: The value of the second smallest element
 */
void	push_small_two(t_stack **a, t_stack **b, int small, int sec_small)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		while ((*a)->num != small && (*a)->num != sec_small)
		{
			if ((*a)->next->num == small || (*a)->next->num == sec_small
				|| (*a)->next->next->num == small
				|| (*a)->next->next->num == sec_small)
				rotate_it(a, 'a');
			else
				rev_rot_it(a, 'a');
		}
		push_it(b, a, 'b');
		i++;
	}
}

/* Sort a stack of five elements
 *
 * This function sorts a stack of exactly five elements. It pushes the two smallest
 * elements to stack B, sorts the remaining three elements in stack A, and then
 * pushes the two smallest elements back to stack A in the correct order.
 *
 * @param a: Pointer to stack A
 * @param b: Pointer to stack B
 */
void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		small;
	int		sec_small;

	current = *a;
	while (current)
	{
		if (current->rank == 0)
			small = current->num;
		if (current->rank == 1)
			sec_small = current->num;
		current = current->next;
	}
	push_small_two(a, b, small, sec_small);
	sort_three(a);
	push_it(a, b, 'a');
	push_it(a, b, 'a');
	if ((*a)->rank == 1)
		swap_it(a, 'a');
}
