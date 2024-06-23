#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>

#define INTMAX 2147483647
#define INTMIN -2147483648

typedef struct s_stacks
{
    char **args;
    t_list *stack_a;
    t_list *stack_b;
    int count_a;
    int count_b;
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
} t_stacks;

void check_args(t_stacks *stacks);
void exit_error(t_stacks *stacks);
void free_stack(t_list *stack);
#endif