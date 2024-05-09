/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:51:55 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/06 22:57:17 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_push
{
	int number;
	int index;
	struct s_push *next;
} t_push;

void	check_ifnumber(int ac, char **av);
int		ifnumber(char *s);
char	**ft_split(char *s, char c);
void	error(void);
int		ft_isdigit(int c);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t num_elements, size_t element_size);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strlen(char *s);
void	ft_isalpha(char *c);
void	sign_check(char *s);
void	ft_strcpy(char *dst, const char *src);
long	ft_atoi(char *str);

#endif