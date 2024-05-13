/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:09:54 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/13 07:14:31 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first_two(t_push **stack_a)
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
}

void	ss(t_push **stack_a, t_push **stack_b)
{
	swap_first_two(stack_a);
	swap_first_two(stack_b);
	write(1, "ss\n", 3);
}

void	push(t_push **add, t_push **remove)
{
	t_push	*tmp;

	if (!remove || !*remove)
		return ;
	tmp = *remove;
	*remove = (*remove)->next;
	tmp->next = NULL;
	ft_lstadd_front(add, tmp);
}

void	rotate(t_push **stack)
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
	ft_lstadd_back(&tmp , tmp2);
	(*stack) = tmp;
}

void	rr(t_push **stack_a, t_push **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate(t_push **stack)
{
	t_push	*tmp;
	t_push	*lst;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	tmp = (*stack)->next;
	lst = ft_lstlast(*stack);
	lst->next = *stack;
	(*stack)->next = NULL;
	*stack = tmp;
	
}