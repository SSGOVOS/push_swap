/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 02:17:09 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/15 02:00:21 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_index(t_push **stack)
{
	t_push	*tmp1;
	t_push	*tmp2;

	if (!(*stack)->next)
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

	if (!(*stack)->next)
		return (0);
	tmp1 = (*stack);
	tmp2 = (*stack)->next;
	while (tmp2)
	{
		if (tmp1->index > tmp2->index)
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