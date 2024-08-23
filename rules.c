/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <aben-hss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 07:12:26 by aben-hss          #+#    #+#             */
/*   Updated: 2024/08/23 13:21:25 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the first two elements at the top of a stack
 *
 * This function swaps the top two elements of the given stack.
 * It also prints the corresponding operation ('sa' or 'sb') to stdout.
 *
 * @param stack: Pointer to the stack to perform the swap operation on
 * @param c: Character indicating which stack is being operated on ('a' or 'b')
 */
void	swap_it(t_stack **stack, char c)
{
	t_stack	*temp_two;
	t_stack	*temp;

	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
	if (*stack && (*stack)->next)
	{
		temp_two = (*stack)->next->next;
		temp = (*stack);
		*stack = (*stack)->next;
		(*stack)->next = temp;
		temp->next = temp_two;
	}
}

/* Push the top element from one stack to another
 *
 * This function moves the top element of the source stack to the top of the destination stack.
 * It also prints the corresponding operation ('pa' or 'pb') to stdout.
 *
 * @param stack_dest: Pointer to the destination stack
 * @param stack_src: Pointer to the source stack
 * @param c: Character indicating which stack is receiving the push ('a' or 'b')
 */
void	push_it(t_stack **stack_dest, t_stack **stack_src, char c)
{
	t_stack	*temp;

	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
	if (*stack_src == NULL)
		return ;
	temp = *stack_src;
	*stack_src = (*stack_src)->next;
	temp->next = *stack_dest;
	*stack_dest = temp;
}

/* Rotate a stack (shift up all elements by 1)
 *
 * This function moves the first element of the stack to the bottom.
 * It also prints the corresponding operation ('ra' or 'rb') to stdout.
 *
 * @param stack: Pointer to the stack to perform the rotate operation on
 * @param c: Character indicating which stack is being operated on ('a' or 'b')
 */
void	rotate_it(t_stack **stack, char c)
{
	t_stack	*temp;
	t_stack	*new_head;

	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
	if (*stack && (*stack)->next)
	{
		new_head = (*stack)->next;
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = *stack;
		(*stack)->next = NULL;
		*stack = new_head;
	}
}

/* Reverse rotate a stack (shift down all elements by 1)
 *
 * This function moves the last element of the stack to the top.
 * It also prints the corresponding operation ('rra' or 'rrb') to stdout.
 *
 * @param stack: Pointer to the stack to perform the reverse rotate operation on
 * @param c: Character indicating which stack is being operated on ('a' or 'b')
 */
void	rev_rot_it(t_stack **stack, char c)
{
	t_stack	*temp;
	t_stack	*last;

	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
	if (*stack && (*stack)->next)
	{
		temp = *stack;
		while (temp->next->next != NULL)
			temp = temp->next;
		last = temp->next;
		temp->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}
