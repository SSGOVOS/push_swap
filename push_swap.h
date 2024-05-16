/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubine <amoubine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:51:55 by amoubine          #+#    #+#             */
/*   Updated: 2024/05/16 04:35:42 by amoubine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 46
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_push
{
	int				number;
	int				index;
	struct s_push	*next;
}					t_push;

void				check_ifnumber(int ac, char **av);
int					ifnumber(char *s);
char				**ft_split(char *s, char c);
void				error(void);
int					ft_isdigit(int c);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_calloc(size_t num_elements, size_t element_size);
size_t				ft_strlcpy(char *dst, char *src, size_t size);
char				*ft_strdup(char *s);
char				*ft_substr(char *s, size_t start, size_t len);
size_t				ft_strlen(char *s);
void				ft_isalpha(char *c);
void				sign_check(char *s);
void				ft_strcpy(char *dst, const char *src);
long				ft_atoi(char *str);
void				swap_first_two(t_push **stack_a, int i);
int					lenght(int ac, char **av);
char				*convert(int ac, char **av);
void				check_dup2(long *a, int d);
void				check_duplicates(char **ptr);
t_push				*lstnew(int number);
void				fnfree(char **ptr);
void				free_lst(t_push **stack);
int					ft_lstsize(t_push **stack);
void				ft_lstadd_back(t_push **lst, t_push *new);
t_push				*ft_lstlast(t_push *lst);
void				ft_lstadd_front(t_push **list, t_push *new);
void				push(t_push **add, t_push **remove, int i);
void				ss(t_push **stack_a, t_push **stack_b);
void				swap_first_two(t_push **stack_a, int i);
void				rotate(t_push **stack, int i);
void				sort_index(t_push **stack);
int					check_sorted(t_push **stack);
int					high_index(t_push **stack);
int					find_index(t_push **stack, int p);
void				reverse_rotate(t_push **stack, int i);
void				sort3(t_push **stack);
void				sort4(t_push **stack_a, t_push **stack_b);
void				sort5(t_push **stack_a, t_push **stack_b);
int					find_index_range(t_push *stack_a, int x, int p);
char				*ft_strdup(char *s);
char				*ft_strjoin(char *s1, char *s2);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*get_next_line(int fd);
void				rrr(t_push **stack_a, t_push **stack_b);
void				rr(t_push **stack_a, t_push **stack_b);
char				*ft_strdup(char *s);

#endif