/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgotzlov <vgotzlov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:11:06 by vgotzlov          #+#    #+#             */
/*   Updated: 2025/11/23 15:15:15 by vgotzlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa: swap a - swap the first 2 elements at the top of stack a */
void	sa(t_stack *a, int print)
{
	t_node	*first;
	t_node	*second;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
	if (print)
		print_operation("sa");
}

/* sb: swap b - swap the first 2 elements at the top of stack b */
void	sb(t_stack *b, int print)
{
	t_node	*first;
	t_node	*second;

	if (!b || !b->top || !b->top->next)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
	if (print)
		print_operation("sb");
}

/* ss: sa and sb at the same time */
void	ss(t_stack *a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	print_operation("ss");
}
