#include "push_swap.h"

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
