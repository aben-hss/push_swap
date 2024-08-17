/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <aben-hss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 07:12:11 by aben-hss          #+#    #+#             */
/*   Updated: 2024/07/28 00:10:17 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct t_stack
{
	int				num;
	int				rank;
	struct t_stack	*next;
}	t_stack;

t_stack	*new_node(int num);
t_stack	*store_nums(char **nums);
size_t	get_stack_size(t_stack *stack);
int		cs_atoi(char *str, char **free_it);
void	check_overflow(char **chars);
int		check_dubs(t_stack *a);
int		check_sorted(t_stack *stack);
void	clear_stack(t_stack *stack);
void	add_to_stack(t_stack **head, t_stack *new);
void	rank_nodes(t_stack *stack);
void	swap_it(t_stack **stack, char c);
void	push_it(t_stack **stack_dest, t_stack **stack_src, char c);
void	rotate_it(t_stack **stack, char c);
void	rev_rot_it(t_stack **stack, char c);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	sort_all(t_stack **a, t_stack **b);
int		initialize_stacks(char **av, t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b, size_t stack_size);

#endif