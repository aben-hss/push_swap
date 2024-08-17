/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <aben-hss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:50:52 by aben-hss          #+#    #+#             */
/*   Updated: 2024/07/28 00:36:12 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_stack
{
	int				num;
	int				rank;
	struct s_stack	*next;
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
void	swap_it(t_stack **stack);
void	push_it(t_stack **stack_dest, t_stack **stack_src);
void	rotate_it(t_stack **stack);
void	rev_rot_it(t_stack **stack);
int		initialize_stacks(char **av, t_stack **a, t_stack **b);
char	*get_next_line(int fd);

#endif