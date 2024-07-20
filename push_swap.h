#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <libc.h>
#include "./libft/libft.h"

typedef struct t_stack{
    int num;
    int rank;
    struct t_stack *next; 
}t_stack;

int	cs_atoi(char *str, char **free_it);
t_stack *new_node(int num);
t_stack *store_nums(char **nums);
int check_dubs(t_stack *a);
int check_storted(t_stack *stack);
void clear_stack(t_stack *stack);
size_t  get_stack_size(t_stack *stack);
void add_to_stack(t_stack **head, t_stack *new);
void rank_nodes(t_stack *stack);
void swap_it(t_stack **stack, char c);
void push_it(t_stack **stack_dest, t_stack **stack_src, char c);
void rotate_it(t_stack **stack, char c);
void rev_rot_it(t_stack **stack, char c);
void sort_three(t_stack **a, t_stack **b);
void sort_four(t_stack **a, t_stack **b);
void sort_five(t_stack **a, t_stack **b);
void sort_chankitos(t_stack **a, t_stack **b);
void print_stack(t_stack *test);
#endif