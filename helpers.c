/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:52:02 by eyasa             #+#    #+#             */
/*   Updated: 2024/06/27 14:52:03 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks *new_stacks()
{
    t_stacks *stacks;

    stacks = (t_stacks *)malloc(sizeof(t_stacks));
    if (stacks == NULL)
    {
        ft_printf("Error\n");
        exit(-1);
    }
    stacks->stack_a = NULL;
    stacks->stack_b = NULL;
    stacks->count_a = 0;
    stacks->count_b = 0;
    stacks->args = NULL;
    stacks->ra = 0;
    stacks->rb = 0;
    stacks->rr = 0;
    stacks->rra = 0;
    stacks->rrb = 0;
    stacks->rrr = 0;
    return (stacks);
}

void exit_error(t_stacks *stacks)
{
    int i;

    i = 0;
    while (stacks->args[i])
        free(stacks->args[i++]);
    free(stacks->args);
    free_stack(stacks->stack_a);
    free_stack(stacks->stack_b);
    free(stacks);
    ft_printf("Error\n");
    exit(-1);
}

void free_stack(t_list *stack)
{
    t_list *node;
    t_list *temp;

    node = stack;
    while (node)
    {
        free(node->content);
        temp = node;
        node = node->next;
        free(temp);
    }
}
