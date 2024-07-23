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

t_stack	*store_nums(char **nums)
{
	t_stack	*head;
	char	**clear;

	clear = nums;
	head = NULL;
	while (*nums)
	{
		add_to_stack(&head, new_node(cs_atoi(*nums, NULL)));
		nums++;
	}
	dealloc(clear);
	return (head);
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

int	check_dubs(t_stack *a)
{
	t_stack	*temp;
	int		temp_int;

	while (a)
	{
		temp_int = a->num;
		temp = a->next;
		while (temp)
		{
			if (temp_int == temp->num)
				return (1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}

int	check_storted(t_stack *stack)
{
	while (stack)
	{
		if (stack->next && stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
