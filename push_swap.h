/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <aben-hss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 07:12:11 by aben-hss          #+#    #+#             */
/*   Updated: 2024/08/23 13:43:24 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>

// Define the structure for stack nodes
typedef struct t_stack
{
	int				num;            // The number stored in the node
	int				rank;           // The rank of the number (used for sorting)
	struct t_stack	*next;          // Pointer to the next node
}	t_stack;

// Function prototypes

// Stack management functions
t_stack	*new_node(int num);                     // Create a new stack node
t_stack	*store_nums(char **nums);               // Store numbers in the stack
size_t	get_stack_size(t_stack *stack);         // Get the size of the stack
void	clear_stack(t_stack *stack);            // Free the entire stack
void	add_to_stack(t_stack **head, t_stack *new); // Add a node to the stack

// Input processing and validation functions
int		cs_atoi(char *str, char **free_it);     // Custom atoi function
void	check_overflow(char **chars);           // Check for integer overflow
int		check_dubs(t_stack *a);                 // Check for duplicate numbers
int		check_sorted(t_stack *stack);           // Check if stack is sorted

// Sorting helper functions
void	rank_nodes(t_stack *stack);             // Assign ranks to stack nodes

// Stack operations
void	swap_it(t_stack **stack, char c);       // Swap the top two elements
void	push_it(t_stack **stack_dest, t_stack **stack_src, char c); // Push top element to another stack
void	rotate_it(t_stack **stack, char c);     // Rotate the stack upwards
void	rev_rot_it(t_stack **stack, char c);    // Rotate the stack downwards

// Sorting algorithms
void	sort_three(t_stack **a);                // Sort 3 elements
void	sort_four(t_stack **a, t_stack **b);    // Sort 4 elements
void	sort_five(t_stack **a, t_stack **b);    // Sort 5 elements
void	sort_all(t_stack **a, t_stack **b);     // Sort any number of elements

// Main program functions
int		initialize_stacks(char **av, t_stack **a, t_stack **b); // Initialize stacks from input
void	sort_stack(t_stack **a, t_stack **b, size_t stack_size); // Main sorting function

#endif
