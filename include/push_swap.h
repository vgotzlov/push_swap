/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgotzlov <vgotzlov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:39:46 by vgotzlov          #+#    #+#             */
/*   Updated: 2025/11/23 15:53:30 by vgotzlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef	struct s_data
{
	int	*arr;
	int	size;
}	t_data;

/* Stack node structure */
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

/* Stack structure */
typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* Parsing and validation */
t_data	parse_input(int argc, char **argv);
int		is_number(char *s);
int		is_int_range(char *s);
int		has_duplicate(int *arr, int n);
long	ft_atol(const char *s);

/* Indexing */
void	index_numbers(int *arr, int size);

/* Stack initialization and utility */
t_stack	*init_stack(void);
void	free_stack(t_stack *stack);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
int		is_empty(t_stack *stack);
void	fill_stack(t_stack *stack, int *arr, int size);

/* Stack operations */
void	sa(t_stack *a, int print);
void	sb(t_stack *b, int print);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a, int print);
void	rb(t_stack *b, int print);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, int print);
void	rrb(t_stack *b, int print);
void	rrr(t_stack *a, t_stack *b);

/* Helper functions */
t_node	*get_last_node(t_stack *stack);
void	print_operation(char *op);
int		is_sorted(t_stack *stack);
int		get_max_value(t_stack *stack);
int		get_min_value(t_stack *stack);

/* Sorting algorithms */
void	sort_small(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	radix_sort(t_stack *a, t_stack *b);

/* Utility functions */
void	error_exit(void);
void	ft_putstr_fd(char *s, int fd);

#endif
