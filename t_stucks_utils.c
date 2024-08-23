/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stucks_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <aben-hss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 07:13:01 by aben-hss          #+#    #+#             */
/*   Updated: 2024/08/23 13:35:12 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to create a new node for the stack
t_stack	*new_node(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));  // Allocate memory for the new node
	new->num = num;                 // Set the number value
	new->rank = 0;                  // Initialize rank to 0
	new->next = NULL;               // Set next pointer to NULL
	return (new);
}

// Function to add a new node to the end of the stack
void	add_to_stack(t_stack **head, t_stack *new)
{
	t_stack	*temp;

	temp = *head;
	if (temp)
	{
		// If the stack is not empty, traverse to the last node
		while (temp->next)
			temp = temp->next;
		temp->next = new; // Add the new node at the end
	}
	else
		*head = new; // If the stack is empty, set the new node as the head
}

// Function to get the size of the stack
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

// Function to clear (free) the entire stack
void	clear_stack(t_stack *stack)
{
	t_stack	*clear;

	while (stack)
	{
		clear = stack;
		stack = stack->next;
		free(clear); // Free each node
	}
}
