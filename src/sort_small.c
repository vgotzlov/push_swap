/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgotzlov <vgotzlov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:39:54 by vgotzlov          #+#    #+#             */
/*   Updated: 2025/11/23 15:42:35 by vgotzlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1 0 2 -> sa
2 1 0 -> sa + rra
2 0 1 -> ra
0 2 1 -> sa + ra
1 2 0 -> rra
*/
void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (a->size != 3)
		return ;
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;

	if (first > second && second < third && first < third)
		sa(a, 1);
	else if (first > second && second > third)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(a, 1);
}

/* Find the position of minimum value in stack */
static int	find_min_position(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		pos;
	int		min_pos;

	current = stack->top;
	min = current->value;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

/* Move the minimum value to the top of stack a */
static void	move_min_to_top(t_stack *a)
{
	int	min_pos;
	int	size;

	min_pos = find_min_position(a);
	size = a->size;
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a, 1);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a, 1);
			min_pos++;
		}
	}
}

/* Sort stack with 4 or 5 elements */
static void	sort_four_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

/* Main function to sort small stacks (2-5 elements) */
void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a, 1);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4 || a->size == 5)
		sort_four_five(a, b);
}

