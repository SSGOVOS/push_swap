/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:13:19 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/09 17:07:52 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	*str;
	char	**ptr;
	int		i;
	t_push	*stack_a;
	t_push	*stack_b;
	t_push	*tmp;

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
	push(&stack_b,&stack_a);
	push(&stack_b,&stack_a);
	push(&stack_b,&stack_a);
	tmp = stack_b;
	while (tmp)
	{
		printf("b == %d\n", tmp->number);
		tmp = tmp->next;
	}
	fnfree(ptr);
	free_lst(&stack_a);
	free_lst(&stack_b);
	free(str);
}
