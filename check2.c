/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:36:21 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/16 03:17:18 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_isalpha(char *c)
{
	int	i;

	i = 0;
	sign_check(c);
	while (c[i])
	{
		if (c[i] != 45 && c[i] != 43 && ((c[i] > 64 && c[i] < 91) || (c[i] > 96 && c[i] < 123) || (c[i] >= 33 && c[i] <= 47)))
			error();
		i++;
	}
}

void	sign_check(char *s)
{
	char	*str;

	str = s;
	while (*str)
	{
		if (*str == '-' || *str == '+')
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

void	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	if (dst == NULL)
		return ;
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

long	ft_atoi(char *str)
{
	long	i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - 48);
		if (res * sign > 2147483647 || res * sign < -2147483648)
			error();
		i++;
	}
	return (res * sign);
}
