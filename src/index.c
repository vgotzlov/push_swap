/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgotzlov <vgotzlov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:40:06 by vgotzlov          #+#    #+#             */
/*   Updated: 2025/11/23 14:46:57 by vgotzlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *a, int n)
{
	int	swap;
	int	i;
	int	tmp;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < n - 1)
		{
			if (a[i] > a[i + 1])
			{
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				swap = 1;
			}
			i++;
		}
	}
}

void	index_numbers(int *arr, int size)
{
	int	*sorted;
	int	i;
	int	j;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		error_exit();
	i = 0;
	while (i < size)
	{
		sorted[i] = arr[i];
		i++;
	}
	sort_array(sorted, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == sorted[j])
			{
				arr[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
	free(sorted);
}
