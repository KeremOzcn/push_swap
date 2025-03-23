/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kozcan <kozcan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:55:38 by kozcan            #+#    #+#             */
/*   Updated: 2025/03/21 16:55:42 by kozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ps_push_b(int *stack_a, int *stack_b, int min_idx)
{
	stack_b[stack_b[0] + 1] = stack_a[stack_a[0]];
	if (stack_a[stack_a[0]] < stack_b[min_idx])
		stack_b[min_idx] = stack_a[stack_a[0]];
	else if (stack_a[stack_a[0]] > stack_b[min_idx + 1])
		stack_b[min_idx + 1] = stack_a[stack_a[0]];
	stack_a[0]--;
	stack_b[0]++;
	write(1, "pb\n", 3);
}

void	ps_push_a(int *stack_a, int *stack_b, int min_idx)
{
	stack_a[stack_a[0] + 1] = stack_b[stack_b[0]];
	if (stack_b[stack_b[0]] <= stack_a[min_idx])
		stack_a[min_idx] = stack_b[stack_b[0]];
	if (stack_b[stack_b[0]] >= stack_a[min_idx + 1])
		stack_a[min_idx + 1] = stack_b[stack_b[0]];
	stack_b[0]--;
	stack_a[0]++;
	write(1, "pa\n", 3);
}

void	ps_rotate_x(int *stack_x, int times, int stack_flag)
{
	int	temp;
	int	cursor;

	while (times--)
	{
		cursor = stack_x[0];
		temp = stack_x[cursor];
		while (cursor - 1)
		{
			stack_x[cursor] = stack_x[cursor - 1];
			cursor--;
		}
		stack_x[1] = temp;
		if (stack_flag == 1)
			write(1, "ra\n", 3);
		else if (stack_flag == 2)
			write(1, "rb\n", 3);
	}
}

void	ps_reverse_rotate_x(int *stack_x, int times, int stack_flag)
{
	int	temp;
	int	cursor;
	int	i;

	while (times--)
	{
		i = 1;
		cursor = stack_x[0];
		temp = stack_x[1];
		while (i < cursor)
		{
			stack_x[i] = stack_x[i + 1];
			i++;
		}
		stack_x[cursor] = temp;
		if (stack_flag == 1)
			write(1, "rra\n", 4);
		else if (stack_flag == 2)
			write(1, "rrb\n", 4);
	}
}

void	ps_swap_a(int *stack_a)
{
	int	temp;

	temp = stack_a[3];
	stack_a[3] = stack_a[2];
	stack_a[2] = temp;
	write(1, "sa\n", 3);
}
