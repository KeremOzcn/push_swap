/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kozcan <kozcan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:54:21 by kozcan            #+#    #+#             */
/*   Updated: 2025/03/21 16:54:26 by kozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ps_free_string_array(char **tokens)
{
	int	idx;

	idx = 0;
	while (tokens[idx])
	{
		free(tokens[idx]);
		idx++;
	}
	free(tokens);
}

int	ps_parse_count(int ac, char **av, int idx, int j)
{
	int		elem_count;
	char	**tokens;

	elem_count = 0;
	while (idx < ac)
	{
		tokens = ft_split(av[idx], ' ');
		if (!*tokens)
		{
			ps_free_string_array(tokens);
			ps_exit_error();
		}
		while (tokens[j])
		{
			ps_atoi_extended(tokens[j], tokens);
			j++;
			elem_count++;
		}
		ps_free_string_array(tokens);
		j = 0;
		idx++;
	}
	return (elem_count);
}

int	*ps_fill_stack(int ac, char **av, int *stack_a, int elem_count)
{
	int		idx;
	int		j;
	char	**tokens;

	idx = 1;
	j = 0;
	stack_a = malloc(sizeof(int) * (elem_count + 3));
	if (!stack_a)
		ps_exit_error();
	stack_a[0] = elem_count;
	while (idx < ac)
	{
		tokens = ft_split(av[idx], ' ');
		while (tokens[j])
		{
			stack_a[elem_count] = ps_atoi_extended(tokens[j], tokens);
			j++;
			elem_count--;
		}
		ps_free_string_array(tokens);
		j = 0;
		idx++;
	}
	return (stack_a);
}

int	*ps_init_stack(int ac, char **av)
{
	int	elem_count;
	int	*stack_a;

	stack_a = NULL;
	elem_count = ps_parse_count(ac, av, 1, 0);
	return (ps_fill_stack(ac, av, stack_a, elem_count));
}
