/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:09:54 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/17 02:12:50 by amoubine         ###   ########.fr       */
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
	if (i == 0)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
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
	if (i == 0)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
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
	if (i == 0)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
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
	if (i == 0)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
