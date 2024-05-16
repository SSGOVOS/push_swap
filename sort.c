/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 02:17:09 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/16 23:45:35 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_index(t_push **stack)
{
	t_push	*tmp1;
	t_push	*tmp2;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp1 = (*stack);
	while (tmp1)
	{
		tmp2 = (*stack);
		while (tmp2)
		{
			if (tmp1->number == tmp2->number)
				tmp2 = tmp2->next;
			else if (tmp1->number > tmp2->number)
			{
				tmp1->index++;
				tmp2 = tmp2->next;
			}
			else
				tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

int	check_sorted(t_push **stack)
{
	t_push	*tmp1;
	t_push	*tmp2;

	if (!(*stack) || !(*stack)->next)
		return (0);
	tmp1 = (*stack);
	tmp2 = (*stack)->next;
	while (tmp2)
	{
		if (tmp1->number > tmp2->number)
			return (1);
		else
		{
			tmp2 = tmp2->next;
			tmp1 = tmp1->next;
		}
	}
	return (0);
}

int	find_index(t_push **stack, int p)
{
	t_push	*tmp;
	int		i;

	tmp = (*stack);
	i = 0;
	while (tmp)
	{
		if (tmp->index == p)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	high_index(t_push **stack)
{
	t_push	*tmp;
	int		i;

	tmp = (*stack);
	i = 0;
	while (tmp)
	{
		if (tmp->index > i)
			i = tmp->index;
		tmp = tmp->next;
	}
	return (i);
}

int	find_index_range(t_push *stack_a, int x, int p)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->index <= x || stack_a->index <= x + p)
			break ;
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}
