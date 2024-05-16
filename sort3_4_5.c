/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_4_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 06:14:42 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/16 23:30:44 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_push **stack)
{
	t_push	*tmp;

	tmp = (*stack);
	if (!check_sorted(stack))
		return ;
	if (tmp->index > tmp->next->index && high_index(&tmp) != tmp->index)
		swap_first_two(stack, 0);
	else if (high_index(&tmp) == tmp->index)
	{
		rotate(stack, 0);
		if ((*stack)->index != 0)
			swap_first_two(stack, 0);
	}
	else if (tmp->index == 0 && tmp->next->index == high_index(&tmp))
	{
		swap_first_two(stack, 0);
		rotate(stack, 0);
	}
	else
		reverse_rotate(stack, 0);
}

void	sort4(t_push **stack_a, t_push **stack_b)
{
	if (!check_sorted(stack_a))
		return ;
	if (high_index(stack_a) == (*stack_a)->index)
		push(stack_b, stack_a, 1);
	else if (high_index(stack_a) == (*stack_a)->next->index)
	{
		rotate(stack_a, 0);
		push(stack_b, stack_a, 1);
	}
	else if (high_index(stack_a) == (*stack_a)->next->next->index)
	{
		rotate(stack_a, 0);
		rotate(stack_a, 0);
		push(stack_b, stack_a, 1);
	}
	else
	{
		reverse_rotate(stack_a, 0);
		push(stack_b, stack_a, 1);
	}
	sort3(stack_a);
	push(stack_a, stack_b, 0);
	rotate(stack_a, 0);
}

static void	sort5_util(t_push **stack_a, t_push **stack_b, t_push *tmp)
{
	if (!check_sorted(stack_a))
		return ;
	if (high_index(&tmp) == tmp->next->next->index)
	{
		rotate(stack_a, 0);
		rotate(stack_a, 0);
		push(stack_b, stack_a, 1);
	}
	else if (high_index(&tmp) == tmp->next->next->next->index)
	{
		reverse_rotate(stack_a, 0);
		reverse_rotate(stack_a, 0);
		push(stack_b, stack_a, 1);
	}
	else
	{
		reverse_rotate(stack_a, 0);
		push(stack_b, stack_a, 1);
	}
}

void	sort5(t_push **stack_a, t_push **stack_b)
{
	t_push	*tmp;

	tmp = (*stack_a);
	if (!check_sorted(stack_a))
		return ;
	if (high_index(&tmp) == tmp->index)
		push(stack_b, stack_a, 1);
	else if (high_index(&tmp) == tmp->next->index)
	{
		rotate(stack_a, 0);
		push(stack_b, stack_a, 1);
	}
	else
		sort5_util(stack_a, stack_b, tmp);
	sort4(stack_a, stack_b);
	push(stack_a, stack_b, 0);
	rotate(stack_a, 0);
}
