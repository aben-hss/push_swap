#include "push_swap.h"


void push_to_b(t_stack **a, t_stack **b)
{
    int i = 0;
    int j = get_stack_size(*a) / 7;

    while(*a)
        {
            if((*a)-> rank <= i)
                push_it(b,a,'b');
            else if((*a) -> rank <= i + j)
            {
                push_it(b,a,'b');
                rotate_it(b,'b');
            }
            else
                rotate_it(a,'a');
            i++;
        }

}
int get_index(t_stack *stack, int rank)
{
    int i = 0;
    while(stack)
    {
        if(stack ->rank == rank)
            return(i);
        stack = stack -> next;
        i++;
    }
    return(-1);
}
void push_to_a(t_stack **a, t_stack **b)
{
    int top_rank_index;
    int size;
    while(*b)
    {
        size = get_stack_size(*b);
        top_rank_index= get_index(*b,size -1);
        //printf("%d\n",top_rank_index);
        if(top_rank_index <= size / 2)
        {
            while((*b) ->rank != size - 1)
                rotate_it(b,'b');
        }
        else
        {
            while((*b) ->rank != size - 1)
                rev_rot_it(b,'b');
        }
        push_it(a,b,'a');
    }
}
void sort_chankitos(t_stack **a, t_stack **b)
{
    push_to_b(a,b);
    push_to_a(a,b);
  // print_stack(*a);
   // print_stack(*b);
}