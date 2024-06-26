/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:51:59 by eyasa             #+#    #+#             */
/*   Updated: 2024/06/29 17:08:25 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*convert_to_one_str(int ac, char **av);
static void	add_stack(t_stacks *stacks);

static char	**parse_args(int ac, char **av, t_stacks *stacks)
{
	char	*str;
	char	**result;

	str = convert_to_one_str(ac, av);
	result = ft_split(str, ' ');
	if (result[0] == NULL)
	{
		free(result[0]);
		free(result);
		free(stacks);
		exit(0);
	}
	return (free(str), result);
}

static char	*convert_to_one_str(int ac, char **av)
{
	int		i;
	char	*str;
	char	*temp;

	i = 0;
	if (ac == 2)
		str = ft_strdup(av[1]);
	else if (ac > 2)
	{
		str = ft_strdup("");
		while (++i < ac)
		{
			temp = ft_strjoin(str, " ");
			free(str);
			str = ft_strjoin(temp, av[i]);
			free(temp);
		}
	}
	return (str);
}

static void	add_stack(t_stacks *stacks)
{
	int		i;
	char	**args;
	int		*num;

	args = stacks->args;
	i = 0;
	while (args[i])
	{
		num = (int *)malloc(sizeof(int));
		if (!num)
			exit_error(stacks);
		*num = ft_atoi(args[i]);
		free(args[i++]);
		ft_lstadd_back(&stacks->stack_a, ft_lstnew(num));
		stacks->count_a++;
	}
	free(stacks->args);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	if (ac < 2)
		return (0);
	stacks = new_stacks();
	stacks->args = parse_args(ac, av, stacks);
	check_args(stacks);
	add_stack(stacks);
	action_optimise(stacks);
	free_stack(stacks->stack_a);
	free(stacks);
}
