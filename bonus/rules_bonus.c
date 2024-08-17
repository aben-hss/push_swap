/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <aben-hss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 07:12:26 by aben-hss          #+#    #+#             */
/*   Updated: 2024/07/27 11:35:07 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_it(t_stack **stack)
{
	t_stack	*temp_two;
	t_stack	*temp;

	if (*stack && (*stack)->next)
	{
		temp_two = (*stack)->next->next;
		temp = (*stack);
		*stack = (*stack)->next;
		(*stack)->next = temp;
		temp->next = temp_two;
	}
}

void	push_it(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*temp;

	if (*stack_src == NULL)
		return ;
	temp = *stack_src;
	*stack_src = (*stack_src)->next;
	temp->next = *stack_dest;
	*stack_dest = temp;
}

void	rotate_it(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*new_head;

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

void	rev_rot_it(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

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
