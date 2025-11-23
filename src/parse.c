/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgotzlov <vgotzlov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:40:00 by vgotzlov          #+#    #+#             */
/*   Updated: 2025/11/23 14:46:22 by vgotzlov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_tokens(int argc, char **argv)
{
	int	i;
	int	count;
	int	in_num;
	char *s;

	i = 1;
	count = 0;
	while (i < argc)
	{
		s = argv[i];
		in_num = 0;
		while (*s)
		{
			if (*s != ' ' && !in_num)
			{
				in_num = 1;
				count++;
			}
			else if (*s == ' ')
				in_num = 0;
			s++;
		}
		i++;
	}
	return (count);
}

static char	**split_tokens(int argc, char **argv)
{
	int		total;
	int		k;
	int		i;
	char	*s;
	char	**out;

	total = count_tokens(argc, argv);
	out = malloc(sizeof(char *) * (total + 1));
	if (!out)
		error_exit();
	k = 0;
	i = 1;
	while (i < argc)
	{
		s = argv[i];
		while (*s)
		{
			while (*s == ' ')
				s++;
			if (*s)
			{
				out[k++] = s;
				while (*s && *s != ' ')
					s++;
				if (*s == ' ')
				{
					*s = '\0';
					s++;
				}
			}
		}
		i++;
	}
	out[k] = NULL;
	return (out);
}

t_data parse_input(int argc, char **argv)
{
	t_data  data;
	char	**tokens;
	int		i;
	data.arr = NULL;
	data.size = 0;

	if (argc < 2)
		return (data);
	tokens = split_tokens(argc, argv);
	i = 0;
	while (tokens[i])
		i++;
	data.size = i;
	data.arr = malloc(sizeof(int) * i);
	if (!data.arr)
		error_exit();
	i = 0;
	while (tokens[i])
	{
		if (!is_number(tokens[i]) || !is_int_range(tokens[i]))
			error_exit();
		data.arr[i] = (int)ft_atol(tokens[i]);
		i++;
	}
	if (has_duplicate(data.arr, data.size))
		error_exit();
	free(tokens);
	return (data);
}

