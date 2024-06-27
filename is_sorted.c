/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:49:49 by eyasa             #+#    #+#             */
/*   Updated: 2024/06/27 18:55:39 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_list *stack)
{
	t_list	*temp;

	if (!stack)
		return (0);
	temp = stack;
	while (temp->next != NULL)
	{
		if (*(int *)temp->content > *(int *)temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int is_reverse_sort(t_list *stack)
{
	t_list *temp;

	if (!stack)
		return (0);
	temp = stack;
	while (temp->next != NULL)
	{
		if (*(int *)temp->content < *(int *)temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}
