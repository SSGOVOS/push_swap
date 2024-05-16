/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:02:50 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/16 23:49:11 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lenght(int ac, char **av)
{
	int	i;
	int	len;

	len = 0;
	i = 1;
	while (i < ac)
	{
		len += ft_strlen(av[i]) + 1;
		i++;
	}
	return (len);
}

char	*convert(int ac, char **av)
{
	int		len;
	char	*result;
	int		i;
	int		index;

	len = lenght(ac, av);
	result = malloc(len);
	if (!result)
		return (NULL);
	i = 1;
	index = 0;
	while (i < ac)
	{
		ft_strcpy(result + index, av[i]);
		if (i + 1 < ac)
		{
			index = ft_strlen(result);
			result[index] = ' ';
		}
		index++;
		i++;
	}
	result[len - 1] = '\0';
	return (result);
}

void	check_dup2(long *a, int d)
{
	int	i;
	int	j;
	int	p;

	p = 0;
	i = 0;
	j = 0;
	while (i < d)
	{
		while (j < d)
		{
			if (a[i] == a[j++])
			{
				if (p == 1)
					error();
				p = 1;
			}
		}
		p = 0;
		j = 0;
		i++;
	}
}

void	check_duplicates(char **ptr)
{
	int		i;
	int		d;
	long	*a;

	i = -1;
	d = 0;
	while (ptr[d])
		d++;
	a = malloc(sizeof(long) * d);
	while (ptr[++i])
		a[i] = ft_atoi(ptr[i]);
	check_dup2(a, d);
	free(a);
}

t_push	*lstnew(int number)
{
	t_push	*n;

	n = malloc(sizeof(t_push));
	n->number = number;
	n->index = 0;
	n->next = NULL;
	return (n);
}
