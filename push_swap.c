/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:13:19 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/06 16:49:59 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

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
		strcpy(result + index, av[i]);
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
#include <stdio.h>

int	main(int ac, char **av)
{
	char *str;
	char **ptr;
	int i;
	int number;

	i = 0;
	if (ac == 1)
		return (0);
	check_ifnumber(ac, av);
	str = convert(ac, av);
	printf("%s\n", str);
	ptr = ft_split(str , ' ');
	while (ptr[i])
	{
		printf("%s\n", ptr[i]);
		i++;
	}
	i = 0;
	number = ft_atoi(ptr[i]);
	while (ptr[i])
	{
		printf("%i" , ft_atoi(ptr[i]));
		i++;
	}

	free(str);
	free(ptr);
}