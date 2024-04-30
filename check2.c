/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:36:21 by amoubine          #+#    #+#             */
/*   Updated: 2024/04/30 10:09:18 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_isalpha(char *c)
{
	int i;

	i = 0;
	sign_check(c);
	while (c[i])
	{
		if ((c[i] > 64 && c[i] < 91) || (c[i] > 96 && c[i] < 123))
			error();
		i++;
	}
}

void sign_check(char *s)
{
	char *str;

	str = s;
	while(*str)
	{
		if(*str == '-' || *str == '+')
		{
			str++;
			if ((*str) == '-' || (*str) == '+')
			{
				error();
			}
		}
		str++;
	}
}