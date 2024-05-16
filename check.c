/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:52:25 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/16 23:45:22 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ifnumber(char *s)
{
	char	*str;

	str = s;
	if (!*str)
		error();
	ft_isalpha(s);
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str == '-' || *str == '+')
		{
			str--;
			if (ft_isdigit(*str))
				error();
			str++;
			str++;
		}
		if (!ft_isdigit(*str))
			error();
		str++;
		while (*str == ' ')
			str++;
	}
	return (1);
}

void	check_ifnumber(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ifnumber(av[i]);
		i++;
	}
}
