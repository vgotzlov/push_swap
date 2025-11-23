/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgotzlov <vgotzlov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:11:45 by vgotzlov          #+#    #+#             */
/*   Updated: 2025/11/23 15:16:19 by vgotzlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ra: rotate a - shift up all elements of stack a by 1 */
void	ra(t_stack *a, int print)
{
	t_node	*first;
	t_node	*last;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	last = get_last_node(a);
	a->top = first->next;
	first->next = NULL;
	last->next = first;
	if (print)
		print_operation("ra");
}

/* rb: rotate b - shift up all elements of stack b by 1 */
void	rb(t_stack *b, int print)
{
	t_node	*first;
	t_node	*last;

	if (!b || !b->top || !b->top->next)
		return ;
	first = b->top;
	last = get_last_node(b);
	b->top = first->next;
	first->next = NULL;
	last->next = first;
	if (print)
		print_operation("rb");
}

/* rr: ra and rb at the same time */
void	rr(t_stack *a, t_stack *b)
{
	ra(a, 0);
	rb(b, 0);
	print_operation("rr");
}


