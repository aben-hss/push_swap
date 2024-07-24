#include "push_swap.h"

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

// void	sort_five(t_stack **a, t_stack **b)
// {
// 	t_stack	*current;
// 	int		small;
// 	int		sec_small;
// 	int		i;

// 	current = *a;
// 	while (current)
// 	{
// 		if (current->rank == 0)
// 			small = current->num;
// 		if (current->rank == 1)
// 			sec_small = current->num;
// 		current = current->next;
// 	}
// 	i = 0;
// 	while (i < 2)
// 	{
// 		while ((*a)->num != small && (*a)->num != sec_small)
// 		{
// 			if ((*a)->next->num == small || (*a)->next->num == sec_small
// 				|| (*a)->next->next->num == small
// 				|| (*a)->next->next->num == sec_small)
// 				rotate_it(a, 'a');
// 			else
// 				rev_rot_it(a, 'a');
// 		}
// 		push_it(b, a, 'b');
// 		i++;
// 	}
// 	sort_three(a, b);
// 	push_it(a, b, 'a');
// 	push_it(a, b, 'a');
// 	if ((*a)->rank == 1)
// 		swap_it(a, 'a');
// }
