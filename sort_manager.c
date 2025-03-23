/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kozcan <kozcan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:56:26 by kozcan            #+#    #+#             */
/*   Updated: 2025/03/21 16:56:30 by kozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	ps_minmax_bounds(int *stack_a, int min_idx)
{
	int	idx_max;

	stack_a[min_idx] = 2147483647;
	stack_a[min_idx + 1] = -2147483648;
	idx_max = stack_a[0];
	while (idx_max)
	{
		if (stack_a[idx_max] <= stack_a[min_idx])
			stack_a[min_idx] = stack_a[idx_max];
		if (stack_a[idx_max] >= stack_a[min_idx + 1])
			stack_a[min_idx + 1] = stack_a[idx_max];
		idx_max--;
	}
}

void	ps_rotate_and_pb(int *stack_a, int *stack_b, int moves, int min_idx)
{
	if (moves < 0)
		ps_reverse_rotate_x(stack_b, -moves, 2);
	else if (moves > 0)
		ps_rotate_x(stack_b, moves, 2);
	ps_push_b(stack_a, stack_b, min_idx);
}

void	ps_pre_sort(int *stack_a, int *stack_b, int min_idx)
{
	while (stack_a[0] - 3)
	{
		if (stack_a[stack_a[0]] <= stack_b[min_idx]
			&& stack_a[stack_a[0]] >= stack_b[min_idx + 1])
		{
			stack_b[min_idx] = stack_a[stack_a[0]];
			stack_b[min_idx + 1] = stack_a[stack_a[0]];
			ps_push_b(stack_a, stack_b, min_idx);
			continue ;
		}
		ps_calc_move(stack_a, stack_b, min_idx);
		ps_calc_move(stack_a, stack_b, min_idx);
		if (stack_a[stack_a[0]] <= stack_b[min_idx])
			ps_rotate_and_pb(stack_a, stack_b,
				ps_find_index(stack_b, stack_b[min_idx + 1]), min_idx);
		else
			ps_rotate_and_pb(stack_a, stack_b,
				ps_calc_b(stack_b, stack_a[stack_a[0]]), min_idx);
	}
	ps_three_sort(stack_a, 1);
}

void	ps_sort_stack(int *stack_a)
{
	int	*stack_b;
	int	min_idx;

	min_idx = stack_a[0] + 1;
	stack_b = malloc(sizeof(int) * (stack_a[0] + 3));
	if (!stack_b)
		ps_exit_error();
	stack_b[min_idx] = 2147483647;
	stack_b[min_idx + 1] = -2147483648;
	stack_b[0] = 0;
	ps_pre_sort(stack_a, stack_b, min_idx);
	ps_minmax_bounds(stack_a, min_idx);
	ps_future_flow(stack_a, stack_b, min_idx);
	free(stack_a);
	free(stack_b);
}

void	ps_exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
