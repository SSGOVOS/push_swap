/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:05:54 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/09 17:01:52 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*ft_lstlast(t_push *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
void	ft_lstadd_back(t_push **lst, t_push *new)
{
	t_push	*x;

	if (!lst)
		return ;
	if ((*lst))
	{
		x = ft_lstlast(*lst);
		x->next = new;
	}
	else
		*lst = new;
}
int lstsize(t_push **stack)
{
	t_push *tmp;
	int i;

	i = 0;
	tmp = *stack;
	if (!stack || !*stack)
		return (0);
	while (tmp)
	{
		i++;	
		tmp = tmp->next;
	}
	return (i);
}

void	ft_lstadd_front(t_push **list, t_push *new)
{
	if (!new || !list)
		return ;
	new->next = *list;
	*list = new;
}

void	free_lst(t_push **stack)
{
	t_push	*tmp;

	if (!stack || !*stack)
		return ;
	tmp = (*stack);
	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack));
		(*stack) = tmp;
	}
}
