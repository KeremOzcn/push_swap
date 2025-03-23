/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kozcan <kozcan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:56:06 by kozcan            #+#    #+#             */
/*   Updated: 2025/03/21 17:13:52 by kozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ps_three_sort(int *stack_x, int stack_flag)
{
	if (stack_x[2] > stack_x[1] && stack_x[1] > stack_x[3])
	{
		ps_reverse_rotate_x(stack_x, 1, stack_flag);
		ps_swap_a(stack_x);
	}
	else if (stack_x[3] > stack_x[2] && stack_x[2] > stack_x[1])
	{
		ps_rotate_x(stack_x, 1, stack_flag);
		ps_swap_a(stack_x);
	}
	else if (stack_x[3] > stack_x[2] && !(stack_x[3] > stack_x[1]))
		ps_swap_a(stack_x);
	else if (stack_x[3] > stack_x[2] && stack_x[1] > stack_x[2])
		ps_rotate_x(stack_x, 1, stack_flag);
	else if (stack_x[3] > stack_x[1] && !(stack_x[3] > stack_x[2]))
		ps_reverse_rotate_x(stack_x, 1, stack_flag);
}

void	ps_rrr_maker(int *stack_x, int count)
{
	int	temp;
	int	cursor;
	int	i;

	while (count--)
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
		temp = stack_x[1];
	}
}

void	ps_rr_maker(int *stack_x, int count)
{
	int	temp;
	int	cursor;

	while (count--)
	{
		cursor = stack_x[0];
		temp = stack_x[cursor];
		while (cursor - 1)
		{
			stack_x[cursor] = stack_x[cursor - 1];
			cursor--;
		}
		stack_x[1] = temp;
	}
}

void	ps_rotate_both(int *stack_a, int *stack_b, int a, int b)
{
	int	count;

	if (a < b)
		count = a;
	else
		count = b;
	ps_rr_maker(stack_a, count);
	ps_rr_maker(stack_b, count);
	while (count--)
		write(1, "rr\n", 3);
}

void	ps_reverse_rotate_both(int *stack_a, int *stack_b, int a, int b)
{
	int	count;

	if (a <= b)
		count = -b;
	else
		count = -a;
	ps_rrr_maker(stack_a, count);
	ps_rrr_maker(stack_b, count);
	while (count--)
		write(1, "rrr\n", 4);
}
