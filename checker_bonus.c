/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 03:48:32 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/16 23:48:55 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_rr(t_push **stack_a, t_push **stack_b, int i)
{
	if (i == 0)
	{
		reverse_rotate(stack_a, 0);
		reverse_rotate(stack_b, 1);
	}
	else if (i == 1)
	{
		rotate(stack_a, 0);
		rotate(stack_b, 1);
	}
}

char	*ft_strnstr(const char *str, char *to_find, size_t range)
{
	size_t	i;
	size_t	check;
	size_t	to_find_lenght;

	i = 0;
	if (!str && !range)
		return (NULL);
	if (!*to_find)
		return ((char *)str);
	to_find_lenght = ft_strlen(to_find);
	while (str[i] && to_find_lenght <= range - i)
	{
		check = 0;
		while (str[i + check] == to_find[check] && to_find[check])
			check++;
		if (to_find[check] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

void	is_valid(t_push **a, t_push **b, char *line)
{
	if (ft_strnstr(line, "sa\n", 3))
		swap_first_two(a, 1);
	else if (ft_strnstr(line, "pa\n", 3))
		push(a, b, 1);
	else if (ft_strnstr(line, "pb\n", 3))
		push(b, a, 1);
	else if (ft_strnstr(line, "sb\n", 3))
		swap_first_two(b, 1);
	else if (ft_strnstr(line, "ra\n", 3))
		rotate(a, 1);
	else if (ft_strnstr(line, "rb\n", 3))
		rotate(b, 1);
	else if (ft_strnstr(line, "rr\n", 3))
		rrr_rr(a, b, 1);
	else if (ft_strnstr(line, "rra\n", 4))
		reverse_rotate(a, 1);
	else if (ft_strnstr(line, "rrb\n", 4))
		reverse_rotate(b, 1);
	else if (ft_strnstr(line, "rrr\n", 4))
		rrr_rr(a, b, 0);
	else if (ft_strnstr(line, "ss\n", 4))
		ss(a, b);
	else
		error();
}

void	read_instructions(t_push **stack_a, t_push **stack_b)
{
	char	*line;

	sort_index(stack_a);
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		is_valid(stack_a, stack_b, line);
		free(line);
	}
	if (*stack_b)
	{
		write(1, "KO", 2);
		free_lst(stack_b);
	}
	else if (check_sorted(stack_a))
	{
		write(1, "KO", 2);
		free_lst(stack_b);
	}
	else
		write(1, "OK", 2);
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
	read_instructions(&stack_a, &stack_b);
	fnfree(ptr);
	free_lst(&stack_a);
	free_lst(&stack_b);
	free(str);
}
