/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:51:54 by eyasa             #+#    #+#             */
/*   Updated: 2024/06/27 20:02:03 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct s_stacks
{
	char	**args;
	t_list	*stack_a;
	t_list	*stack_b;
	int		count_a;
	int		count_b;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}			t_stacks;

void		check_args(t_stacks *stacks);
void		exit_error(t_stacks *stacks);
void		free_stack(t_list *stack);
void		actions(t_stacks *stacks, char *str);
void		find_a_index(t_stacks *stacks);
int			node_to_index(t_list *node, t_list *stack);
int			largest_smaller_number(t_list *a_node, t_list *stack_b);
int			smallest_large_number(t_list *b_node, t_list *stack_a);
int			calc_cost(int a_index, int b_index, t_stacks *stacks);
int			is_sort(t_list *stack);
int			is_reverse_sort(t_list *stack);
int			min(int a, int b);
int			max(int a, int b);
void		action_optimise(t_stacks *stacks);
void		actions(t_stacks *stacks, char *str);
t_list		*max_stack(t_list *stack);
t_list		*min_stack(t_list *stack);
t_list		*ft_lst_new_last(t_list *lst);
void		sort_a(t_stacks *stacks);
void		push_to_b(t_stacks *stacks);
void		sort_b(t_stacks *stacks);
void		push_to_a(t_stacks *stacks);
t_stacks	*new_stacks(void);

#endif