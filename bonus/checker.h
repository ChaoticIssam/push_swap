/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:48:40 by iszitoun          #+#    #+#             */
/*   Updated: 2023/01/13 12:28:19 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

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
	int				*ptr;
	int				i;
}					t_dec3;

char				*get_next_line(int fd);
char				*ft_read_str(int fd, char *str);
char				*ft_strchr(char *s, int c);
char				*ft_strjoin(char *left_str, char *buff);
size_t				ft_strlen(const char *s);
char				*ft_get_line(char *str);
char				*ft_new_str(char *str);

t_node				*create_node(int arg);
t_node				*create_stack_a(char **av, int ac);
void				error(void);
int					is_sorted(t_node *stack);
void				ft_putstr_fd(char *s, int fd);

int					size_count(t_node *stack);
int					great_than_limits_checker(char **av);
int					great(char *arg);
int					digit_checker(char **ptr);
int					isit_int(char *ptr);
int					duplication_checker(t_node **stack_a);

int					ft_isdigit(int c);
long				ft_atoi(const char *str);
void				ft_swaper(int *a, int *b);
int					ft_strncmp(char *s1, char *s2);

char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);

int					ft_lstsize(t_node *lst);
void				ft_lstadd_back(t_node **lst, t_node *new);
void				ft_swaper(int *a, int *b);
int					main(int ac, char **av);

void				swap_a(t_node *start);
void				push_a(t_node **stack_b, t_node **stack_a);
void				rotate_a(t_node **stack_a);
void				reverse_rotate_a(t_node **stack_a);

void				swap_b(t_node *start);
void				push_b(t_node **stack_a, t_node **stack_b);
void				rotate_b(t_node **stack_b);
void				reverse_rotate_b(t_node **stack_b);

void				operations(char *tmp, t_node **stack_a, t_node **stack_b);
void				ss(t_node **stack_a, t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);

void				final_step(t_node *stack_a, char **arg);
int					arg_sorted(char **av);
void				ft_free2(char **str);

#endif