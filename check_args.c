/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:52:08 by eyasa             #+#    #+#             */
/*   Updated: 2024/06/29 14:46:44 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		check_args_is_number(t_stacks *stacks);
static void		check_args_is_duplicate(t_stacks *stacks);
static void		check_is_int(t_stacks *stacks);
static long int	ft_atol(const char *str);

void	check_args(t_stacks *stacks)
{
	check_args_is_number(stacks);
	check_is_int(stacks);
	check_args_is_duplicate(stacks);
}

static void	check_args_is_number(t_stacks *stacks)
{
	int		i;
	int		j;
	char	**args;

	i = 0;
	args = stacks->args;
	while (args[i])
	{
		j = 0;
		if ((args[i][j] == '+' || args[i][j] == '-') && args[i][j + 1]
			&& args[i][j + 1] != '0')
			j++;
		while (args[i][j])
		{
			if (!(args[i][j] >= '0' && args[i][j] <= '9'))
				exit_error(stacks);
			j++;
		}
		i++;
	}
}

static void	check_is_int(t_stacks *stacks)
{
	int		i;
	char	**args;

	i = 0;
	args = stacks->args;
	while (args[i])
	{
		if (ft_atol(args[i]) > INTMAX || ft_atol(args[i]) < INTMIN)
			exit_error(stacks);
		i++;
	}
}

static void	check_args_is_duplicate(t_stacks *stacks)
{
	int		i;
	int		j;
	char	**args;

	i = 0;
	args = stacks->args;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[j]) == ft_atoi(args[i]))
				exit_error(stacks);
			j++;
		}
		i++;
	}
}

static long int	ft_atol(const char *str)
{
	int			i;
	int			mult;
	long int	nb;

	mult = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb *= mult;
	return (nb);
}
