/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kozcan <kozcan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:19:51 by kozcan            #+#    #+#             */
/*   Updated: 2025/03/21 17:24:36 by kozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_calc_final_cost(int val_a, int val_b)
{
	if (val_a <= 0 && val_b <= 0)
	{
		if (val_a < val_b)
			return (-val_a);
		else
			return (-val_b);
	}
	else if (val_a > 0 && val_b > 0)
	{
		if (val_a > val_b)
			return (val_a);
		else
			return (val_b);
	}
	else
	{
		if (val_a < val_b)
			return ((-val_a) + val_b);
		else
			return ((-val_b) + val_a);
	}
}

void	ps_perfect_rotate(int *stack_x, int moves, int stack_flag)
{
	if (moves < 0)
		ps_reverse_rotate_x(stack_x, -moves, stack_flag);
	else if (moves > 0)
		ps_rotate_x(stack_x, moves, stack_flag);
}

void	ps_calc_move(int *stack_a, int *stack_b, int min_idx)
{
	int	min_c_index;
	int	cost_b;
	int	cost_a;

	min_c_index = ps_min_cost_index(stack_a, stack_b, min_idx);
	if (stack_a[min_c_index] <= stack_b[min_idx])
		cost_b = ps_find_index(stack_b, stack_b[min_idx + 1]);
	else
		cost_b = ps_calc_b(stack_b, stack_a[min_c_index]);
	cost_a = ps_local_cost(stack_a, min_c_index);
	if (cost_a > 0 && cost_b > 0)
		ps_rotate_both(stack_a, stack_b, cost_a, cost_b);
	else if (cost_a < 0 && cost_b < 0)
		ps_reverse_rotate_both(stack_a, stack_b, cost_a, cost_b);
	else
	{
		ps_perfect_rotate(stack_a, cost_a, 1);
		ps_perfect_rotate(stack_b, cost_b, 2);
	}
}

int	ps_min_cost_index(int *stack_a, int *stack_b, int min_idx)
{
	int	idx_a;
	int	lowest_cost;
	int	best_idx;
	int	temp_cost;
	int	local_temp;

	idx_a = stack_a[0];
	best_idx = idx_a;
	lowest_cost = 2147483647;
	while (idx_a > 0)
	{
		if (stack_a[idx_a] <= stack_b[min_idx])
			temp_cost = ps_find_index(stack_b, stack_b[min_idx + 1]);
		else
			temp_cost = ps_calc_b(stack_b, stack_a[idx_a]);
		local_temp = ps_local_cost(stack_a, idx_a);
		temp_cost = ps_calc_final_cost(temp_cost, local_temp);
		if (temp_cost < lowest_cost)
		{
			best_idx = idx_a;
			lowest_cost = temp_cost;
		}
		idx_a--;
	}
	return (best_idx);
}
