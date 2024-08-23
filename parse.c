/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <aben-hss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 07:12:00 by aben-hss          #+#    #+#             */
/*   Updated: 2024/08/23 13:20:10 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Custom atoi function with error handling for Push Swap
 *
 * This function converts a string to an integer, similar to the standard atoi.
 * However, it includes additional checks for Push Swap requirements:
 * - Handles both positive and negative numbers
 * - Checks for integer overflow
 * - Frees memory and exits on error
 *
 * @param str: The string to convert to an integer
 * @param free_it: A pointer to the string array to free in case of an error
 * @return: The converted integer value
 */
int	cs_atoi(char *str, char **free_it)
{
	unsigned long	ret;
	int				sign;

	ret = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + (*str) - '0';
		str++;
		if (ret > 2147483647 && sign == 1)
			return (dealloc(free_it), ft_putstr_fd("Error\n", 2), exit(1), 0);
		if (ret > 2147483648 && sign == -1)
			return (dealloc(free_it), ft_putstr_fd("Error\n", 2), exit(1), 0);
	}
	return ((int)ret * sign);
}

/* Store numbers from string array into a linked list
 *
 * This function creates a linked list of t_stack nodes from an array of strings.
 * Each string is converted to an integer and stored in a new node.
 *
 * @param nums: Array of strings containing numbers
 * @return: Pointer to the head of the created linked list
 */
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

/* Check for integer overflow in the input strings
 *
 * This function iterates through the array of strings and calls cs_atoi
 * on each to check for potential integer overflow.
 *
 * @param chars: Array of strings to check for overflow
 */
void	check_overflow(char **chars)
{
	int	i;

	i = 0;
	while (chars[i])
		cs_atoi(chars[i++], chars);
}

/* Check for duplicate numbers in the stack
 *
 * This function iterates through the stack and compares each number
 * with all subsequent numbers to detect any duplicates.
 *
 * @param a: Pointer to the head of the stack
 * @return: 1 if duplicates are found, 0 otherwise
 */
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

/* Check if the stack is already sorted
 *
 * This function iterates through the stack and checks if each number
 * is smaller than the next one.
 *
 * @param stack: Pointer to the head of the stack
 * @return: 1 if the stack is sorted, 0 otherwise
 */
int	check_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->next && stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
