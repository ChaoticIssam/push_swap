/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:22:53 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/14 13:51:49 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct s_dec
{
	int				size;
	int				s;
	int				e;
	int				offset;
	int				mid;
	int				index;

}					t_dec;

typedef struct s_dec2
{
	t_node			*top;
	t_node			*add_store;
	char			**ptr;
	int				size;
	int				j;
}					t_dec2;

typedef struct s_dec3
{
	int				size;
	t_node			*stack_a;
	t_node			*stack_b;
	int				*ptr;
	int				i;
}					t_dec3;

typedef struct s_dec4
{
	int				size_ar;
	int				count;
	int				size_sb;
}					t_dec4;

void				swap_a(t_node *start);
void				push_a(t_node **stack_b, t_node **stack_a);
void				rotate_a(t_node **stack_a);
void				reverse_rotate_a(t_node **stack_a);

void				swap_b(t_node *start);
void				push_b(t_node **stack_a, t_node **stack_b);
void				rotate_b(t_node **stack_b);
void				reverse_rotate_b(t_node **stack_b);

int					*array_maker(t_node *stack_a);
void				sort_array(t_node *stack_a, int *str);

int					isit_int(char *ptr);
int					digit_checker(char **ptr);

int					duplication_checker(t_node **stack_a);

int					great(char *arg);
int					great_than_limits_checker(char **av);

t_node				*create_node(int arg);
t_node				*create_stack_a(char **av, int size);

int					is_sorted(t_node *stack);
int					is_exist(t_node **stack_a, int *ar, int start, int end);
int					max_exist(t_node *stack, int elm);
t_node				*get_last_elem(t_node *stack);

int					ft_lstsize(t_node *lst);
void				ft_lstadd_back(t_node **lst, t_node *new);
void				ft_putstr_fd(char *s, int fd);
void				error(void);

int					ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				free_all(char **str);
char				**ft_split(char const *s, char c);

int					ft_isdigit(int c);
long				ft_atoi(const char *str);
void				ft_swaper(int *a, int *b);

int					main(int ac, char **av);
void				printlist(t_node *start);
void				check_size(t_dec3 var);

int					size_count(t_node *stack);
int					get_index(t_node *stack_a, int data);
int					get_min(t_node *stack_a);
int					get_max(t_node *stack_b);

void				its_three(t_node **stack_a);
void				get_elm_intop(t_node **stack, int elm);
void				its_five(t_node **stack_a, t_node **stack_b);
void				its_hundred_omg(t_node **a, t_node **b, int *ar);
void				back_to_a(t_node **stack_b, t_node **stack_a, int *ar);
void				increase_range(t_dec *var);
void				check_list_size(t_dec *var, t_node **stack_a);
void				ft_push(t_node **stack_a, t_node **stack_b, int *ar,
						t_dec *var);
void				push_rotate_a(t_node **b, t_node **a, t_dec4 *v);
void				max_first(t_node **b, t_node **a, t_dec4 *v);

void				no_max_there(t_node **a, t_dec4 *v);
void				max_in_b(t_node **b, int *ar, t_dec4 *v);

#endif
