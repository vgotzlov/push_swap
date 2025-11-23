/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgotzlov <vgotzlov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:11:29 by vgotzlov          #+#    #+#             */
/*   Updated: 2025/11/23 15:14:36 by vgotzlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operation(char *op)
{
	ft_putstr_fd(op, 1);
	ft_putstr_fd("\n", 1);
}

/* pa: push a - take the first element at the top of b and put it at the top of a */
void	pa(t_stack *a, t_stack *b)
{
	int	value;

	if (is_empty(b))
		return ;
	value = pop(b);
	push(a, value);
	print_operation("pa");
}

/* pb: push b - take the first element at the top of a and put it at the top of b */
void	pb(t_stack *a, t_stack *b)
{
	int	value;

	if (is_empty(a))
		return ;
	value = pop(a);
	push(b, value);
	print_operation("pb");
}
