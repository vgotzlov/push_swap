/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgotzlov <vgotzlov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:57:52 by vgotzlov          #+#    #+#             */
/*   Updated: 2025/11/23 15:16:39 by vgotzlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_last_node(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	while (current->next)
		current = current->next;
	return (current);
}

static t_node	*get_second_last_node(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top || !stack->top->next)
		return (NULL);
	current = stack->top;
	while (current->next->next)
		current = current->next;
	return (current);
}

/* rra: reverse rotate a - shift down all elements of stack a by 1 */
void	rra(t_stack *a, int print)
{
	t_node	*second_last;
	t_node	*last;

	if (!a || !a->top || !a->top->next)
		return ;
	second_last = get_second_last_node(a);
	last = second_last->next;
	second_last->next = NULL;
	last->next = a->top;
	a->top = last;
	if (print)
		print_operation("rra");
}

/* rrb: reverse rotate b - shift down all elements of stack b by 1 */
void	rrb(t_stack *b, int print)
{
	t_node	*second_last;
	t_node	*last;

	if (!b || !b->top || !b->top->next)
		return ;
	second_last = get_second_last_node(b);
	last = second_last->next;
	second_last->next = NULL;
	last->next = b->top;
	b->top = last;
	if (print)
		print_operation("rrb");
}

/* rrr: rra and rrb at the same time */
void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	print_operation("rrr");
}
