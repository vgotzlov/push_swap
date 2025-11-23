/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgotzlov <vgotzlov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:39:57 by vgotzlov          #+#    #+#             */
/*   Updated: 2025/11/23 15:39:44 by vgotzlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Get the maximum number of bits needed to represent the largest number */
static int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = get_max_value(stack);
	bits = 0;
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

/*
** Radix Sort Algorithm
**
** Since we've indexed our numbers (0 to n-1), we can use radix sort in base 2
** For each bit position (starting from least significant):
**   - If bit is 0, push to stack b
**   - If bit is 1, rotate in stack a
** After processing all elements, push everything back from b to a
** Repeat for each bit position
**
** Example with 3 numbers [2, 0, 1] (already indexed):
** Binary: [10, 00, 01]
**
** Bit 0 (rightmost):
**   2(10) -> bit=0 -> pb
**   0(00) -> bit=0 -> pb
**   1(01) -> bit=1 -> ra
**   Result: a=[1], b=[0,2]
**   Push back: a=[1,0,2]
**
** Bit 1:
**   1(01) -> bit=0 -> pb
**   0(00) -> bit=0 -> pb
**   2(10) -> bit=1 -> ra
**   Result: a=[2], b=[0,1]
**   Push back: a=[2,0,1]
**   Continue until sorted: a=[0,1,2]
*/
void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		size = a->size;
		j = 0;
		while (j < size)
		{
			if (((a->top->value >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a, 1);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}
