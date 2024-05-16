/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:13:19 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/16 03:17:34 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_to_a(t_push **stack_a, t_push **stack_b)
{
	while ((*stack_b))
	{
		if ((*stack_b)->index == high_index(stack_b)
			|| (*stack_b)->index == high_index(stack_b) - 1)
			push(stack_a, stack_b, 0);
		else if (find_index(stack_b, high_index(stack_b)) > ft_lstsize(stack_b)
			/ 2)
			while (!((*stack_b)->index == high_index(stack_b)
					|| (*stack_b)->index == high_index(stack_b) - 1))
				reverse_rotate(stack_b, 1);
		else
			while (!((*stack_b)->index == high_index(stack_b)
					|| (*stack_b)->index == high_index(stack_b) - 1))
				rotate(stack_b, 1);
		if (check_sorted(stack_a))
		{
			if (ft_lstsize(stack_a) > 1
				&& (*stack_a)->number > (*stack_a)->next->number)
				swap_first_two(stack_a, 0);
		}
	}
}

void	sort_nbr(t_push **stack_a, t_push **stack_b, int p)
{
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize(stack_a);
	while (i < len)
	{
		if ((*stack_a)->index <= i)
		{
			push(stack_b, stack_a, 1);
			rotate(stack_b, 1);
			i++;
		}
		else if ((*stack_a)->index <= i + p)
		{
			push(stack_b, stack_a, 1);
			i++;
		}
		else if (find_index_range(*stack_a, i, p) < ft_lstsize(stack_a) / 2)
			rotate(stack_a, 0);
		else
			reverse_rotate(stack_a, 0);
	}
}

void	whichsort(t_push **stack_a, t_push **stack_b)
{
	int	size;

	sort_index(stack_a);
	size = ft_lstsize(stack_a);
	if (check_sorted(stack_a))
	{
		if (size == 2)
			swap_first_two(stack_a, 0);
		else if (size == 3)
			sort3(stack_a);
		else if (size == 4)
			sort4(stack_a, stack_b);
		else if (size == 5)
			sort5(stack_a, stack_b);
		else if (size <= 400)
			sort_nbr(stack_a, stack_b, 15);
		else
			sort_nbr(stack_a, stack_b, 30);
		push_back_to_a(stack_a, stack_b);
	}
}

int	main(int ac, char **av)
{
	char	*str;
	char	**ptr;
	int		i;
	t_push	*stack_a;
	t_push	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (ac == 1)
		return (0);
	check_ifnumber(ac, av);
	str = convert(ac, av);
	ptr = ft_split(str, ' ');
	check_duplicates(ptr);
	while (ptr[i])
		ft_lstadd_back(&stack_a, lstnew(ft_atoi(ptr[i++])));
	whichsort(&stack_a, &stack_b);
	fnfree(ptr);
	free_lst(&stack_a);
	free_lst(&stack_b);
	free(str);
}
