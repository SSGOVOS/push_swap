/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 02:18:57 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/17 02:19:03 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_rslt(t_push **stack_a, t_push **stack_b)
{
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
