#include "push_swap.h"

void rank_nodes(t_stack *stack)
{
    t_stack *current;
    t_stack *compare;
    int rank;

    current = stack;
    while (current)
    {
        rank = 0;
        compare = stack;
        while (compare)
        {
            if (compare->num < current->num)
                rank++;
            compare = compare->next;
        }
        current->rank = rank;
        current = current->next;
    }
}

void sort_three(t_stack **a, t_stack **b)
{
    int first = (*a)->num;
    int second = (*a)->next->num;
    int third = (*a)->next->next->num;

    if (first > second && second < third && first < third)
        swap_it(a, 'a');
    else if (first > second && second > third)
    {
        swap_it(a, 'a');
        rev_rot_it(a, 'a');
    }
    else if (first > second && second < third && first > third)
        rotate_it(a, 'a');
    else if (first < second && second > third && first < third)
    {
        swap_it(a, 'a');
        rotate_it(a, 'a');
    }
    else if (first < second && second > third && first > third)
        rev_rot_it(a, 'a');
}

void sort_four(t_stack **a, t_stack **b)
{
    int smallest;
    t_stack *current;

    current = *a;
    while (current)
    {
        if (current->rank == 0)
            smallest = current->num;
        current = current->next;
    }
    while ((*a)->num != smallest)
    {
        if ((*a)->next->num == smallest || (*a)->next->next->num == smallest)
            rotate_it(a, 'a');
        else
            rev_rot_it(a, 'a');
    }
    push_it(b, a, 'b');
    sort_three(a, b);
    push_it(a, b, 'a');
}

void sort_five(t_stack **a, t_stack **b)
{
    int smallest, second_smallest, i;
    t_stack *current;


    current = *a;
    while (current)
    {
        if (current->rank == 0)
            smallest = current->num;
        if (current->rank == 1)
            second_smallest = current->num;
        current = current->next;
    }
    i = 0;
    while (i < 2)
    {
        while ((*a)->num != smallest && (*a)->num != second_smallest)
        {
            if ((*a)->next->num == smallest || (*a)->next->num == second_smallest ||
                (*a)->next->next->num == smallest || (*a)->next->next->num == second_smallest)
                rotate_it(a, 'a');
            else
                rev_rot_it(a, 'a');
        }
        push_it(b, a, 'b');
        i++;
    }
    sort_three(a, b);
    push_it(a, b, 'a');
    push_it(a, b, 'a');
    if ((*a)->rank == 1)
        swap_it(a, 'a');
}
