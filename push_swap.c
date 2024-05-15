/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:13:19 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/15 05:47:53 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	whichsort(t_push **stack_a , t_push **stack_b)
{
	int	size;

	size = ft_lstsize(stack_a);
	if(check_sorted(stack_a))
	{
		if(size == 2)
			swap_first_two(stack_a , 0);
		else if(size == 3)
			sort3(stack_a);
		else if(size == 4);
			sort4(stack_a, stack_b);
		else if (size == 5)
			sort5(stack_a , stack_b);
	}
}
void	push_back_to_a(t_push **stack_a, t_push **stack_b)
{
	while ((*stack_b))
	{
		if ((*stack_b)->index == highest_index(*stack_b)
			|| (*stack_b)->index == highest_index(*stack_b) - 1)
			pa(stack_a, stack_b);
		else if (finder(stack_b, highest_index(*stack_b)) > ft_lstsize(*stack_b)
			/ 2)
			while (!((*stack_b)->index == highest_index(*stack_b)
					|| (*stack_b)->index == highest_index(*stack_b) - 1))
				rrb(stack_b);
		else
			while (!((*stack_b)->index == highest_index(*stack_b)
					|| (*stack_b)->index == highest_index(*stack_b) - 1))
				rb(stack_b);
		if (ft_lstsize(*stack_a) > 1
			&& (*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
	}
}

void	sort_nbr(t_push **s_a, t_push **s_b, int p)
{
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize(*s_a);
	while (i < len)
	{
		if ((*s_a)->index <= i)
		{
			pb(s_a, s_b);
			rb(s_b);
			i++;
		}
		else if ((*s_a)->index <= i + p)
		{
			pb(s_a, s_b);
			i++;
		}
		else if (find_index(*s_a, i, p) < ft_lstsize(*s_a) / 2)
			ra(s_a);
		else
			rra(s_a);
	}
}

void	sort100(t_push **s_a, t_push **s_b)
{
	int	len;

	sort_indx(s_a);
	len = ft_lstsize(*s_a);
	if (checked_sorted(s_a, min_indx(*s_a)))
	{
		if (len == 2)
			sa(s_a);
		else if (len == 3)
			sort3(s_a, s_b, min_indx(*s_a));
		else if (len == 4)
			sort4(s_a, s_b, min_indx(*s_a));
		else if (len == 5)
			sort5(s_a, s_b, min_indx(*s_a));
		else if (len <= 400)
			sort_nbr(s_a, s_b, 15);
		else
			sort_nbr(s_a, s_b, 30);
		push_back_to_a(s_a, s_b);
	}
}

int	main(int ac, char **av)
{
	char	*str;
	char	**ptr;
	int		i;
	t_push	*stack_a;
	t_push	*stack_b;
	t_push	*tmp;
	t_push	*tmp2;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (ac == 1)
		return (0);
	check_ifnumber(ac, av);
	str = convert(ac, av);
	printf("%s\n", str);
	ptr = ft_split(str, ' ');
	check_duplicates(ptr);
	while (ptr[i])
		ft_lstadd_back(&stack_a, lstnew(ft_atoi(ptr[i++])));

	fnfree(ptr);
	free_lst(&stack_a);
	free_lst(&stack_b);
	free(str);
}
