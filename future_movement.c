/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   future_movement.c .c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kozcan <kozcan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:52:48 by kozcan            #+#    #+#             */
/*   Updated: 2025/03/21 17:20:51 by kozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_future_flow(int *stack_a, int *stack_b, int min_idx)
{
	while (stack_b[0])
	{
		if (stack_b[stack_b[0]] > stack_a[min_idx + 1])
			ps_rt_and_pa(stack_a, stack_b,
				ps_find_index(stack_a, stack_a[min_idx]), min_idx);
		else
			ps_rt_and_pa(stack_a, stack_b,
				ps_calc_pos(stack_a, stack_b[stack_b[0]]), min_idx);
	}
	ps_turn_stack(stack_a, ps_find_index(stack_a, stack_a[min_idx]), 1);
}

void	ps_turn_stack(int *stack_x, int idx, int flag_stack)
{
	int	num_moves;

	if (idx <= (stack_x[0] / 2))
		num_moves = idx;
	else
		num_moves = stack_x[0] - idx;
	if (num_moves < 0)
		ps_reverse_rotate_x(stack_x, -num_moves, flag_stack);
	else if (num_moves > 0)
		ps_rotate_x(stack_x, num_moves, flag_stack);
}

int	ps_calc_pos(int *stack_a, int num)
{
	int	largest_idx;
	int	counter;
	int	found;

	found = 0;
	counter = stack_a[0];
	while (counter)
	{
		if (stack_a[counter] > num && found == 0)
		{
			largest_idx = counter;
			found = 1;
		}
		else if (stack_a[counter] > num
			&& stack_a[counter] < stack_a[largest_idx])
			largest_idx = counter;
		counter--;
	}
	if (largest_idx == (stack_a[0] / 2) && stack_a[0] % 2 == 0)
		return (stack_a[0] - largest_idx);
	else if (largest_idx <= (stack_a[0] / 2))
		return (-1 * largest_idx);
	else
		return (stack_a[0] - largest_idx);
}

void	ps_rt_and_pa(int *stack_a, int *stack_b, int num_moves, int min_idx)
{
	if (num_moves < 0)
		ps_reverse_rotate_x(stack_a, -num_moves, 1);
	else if (num_moves > 0)
		ps_rotate_x(stack_a, num_moves, 1);
	ps_push_a(stack_a, stack_b, min_idx);
}
