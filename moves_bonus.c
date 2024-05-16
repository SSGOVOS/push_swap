/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 03:55:23 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/16 23:46:34 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first_two(t_push **stack_a, int i)
{
	t_push	*first;
	t_push	*second;
	int		temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	temp = first->number;
	first->number = second->number;
	second->number = temp;
	if (!i)
		return ;
}

void	ss(t_push **stack_a, t_push **stack_b)
{
	swap_first_two(stack_a, 0);
	swap_first_two(stack_b, 1);
}

void	push(t_push **add, t_push **remove, int i)
{
	t_push	*tmp;

	if (!remove || !*remove)
		return ;
	tmp = *remove;
	*remove = (*remove)->next;
	tmp->next = NULL;
	ft_lstadd_front(add, tmp);
	if (!i)
		return ;
}

void	rotate(t_push **stack, int i)
{
	t_push	*tmp;
	t_push	*lst;
	t_push	*tmp2;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	tmp = (*stack)->next;
	lst = (*stack);
	lst = ft_lstlast(lst);
	tmp2 = (*stack);
	tmp2->next = NULL;
	ft_lstadd_back(&tmp, tmp2);
	(*stack) = tmp;
	if (!i)
		return ;
}

void	reverse_rotate(t_push **stack, int i)
{
	t_push	*tmp;
	t_push	*lst;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	tmp = (*stack);
	lst = ft_lstlast((*stack));
	while (tmp)
	{
		if (tmp->next->number == lst->number)
			break ;
		tmp = tmp->next;
	}
	tmp->next = NULL;
	lst->next = (*stack);
	(*stack) = lst;
	if (!i)
		return ;
}
