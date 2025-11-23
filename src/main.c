/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgotzlov <vgotzlov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:40:03 by vgotzlov          #+#    #+#             */
/*   Updated: 2025/11/23 15:52:09 by vgotzlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_stack	*a;
	t_stack	*b;

	data = parse_input(argc, argv);
	if (data.size == 0)
		return (0);
	index_numbers(data.arr, data.size);
	a = init_stack();
	b = init_stack();
	fill_stack(a, data.arr, data.size);
	free(data.arr);
	if (is_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	if (data.size <= 5)
		sort_small(a, b);
	else
		radix_sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
