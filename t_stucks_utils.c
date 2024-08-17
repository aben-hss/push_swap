/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stucks_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <aben-hss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 07:13:01 by aben-hss          #+#    #+#             */
/*   Updated: 2024/07/24 07:33:51 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->num = num;
	new->rank = 0;
	new->next = NULL;
	return (new);
}

void	add_to_stack(t_stack **head, t_stack *new)
{
	t_stack	*temp;

	temp = *head;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*head = new;
}

size_t	get_stack_size(t_stack *stack)
{
	size_t	size;
	t_stack	*copy;

	size = 0;
	copy = stack;
	while (copy)
	{
		copy = copy->next;
		size++;
	}
	return (size);
}

void	clear_stack(t_stack *stack)
{
	t_stack	*clear;

	while (stack)
	{
		clear = stack;
		stack = stack->next;
		free(clear);
	}
}
