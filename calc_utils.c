/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kozcan <kozcan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:53:18 by kozcan            #+#    #+#             */
/*   Updated: 2025/03/21 16:53:23 by kozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_calc_b(int *stack_x, int num)
{
	int	temp_idx;
	int	counter;
	int	found;

	found = 0;
	counter = stack_x[0];
	while (counter)
	{
		if (stack_x[counter] < num && found == 0)
		{
			temp_idx = counter;
			found = 1;
		}
		else if (stack_x[counter] < num && stack_x[counter] > stack_x[temp_idx])
			temp_idx = counter;
		counter--;
	}
	if (temp_idx <= (stack_x[0] / 2))
		return (-temp_idx);
	else
		return (stack_x[0] - temp_idx);
}

int	ps_find_index(int *stack_x, int num)
{
	int	idx;

	idx = 1;
	while (1)
	{
		if (stack_x[idx] == num)
			break ;
		idx++;
	}
	if (idx <= (stack_x[0] / 2))
		return (-idx);
	else
		return (stack_x[0] - idx);
}

int	ps_local_cost(int *stack_x, int idx)
{
	if (idx <= (stack_x[0] / 2))
		return (-idx);
	else
		return (stack_x[0] - idx);
}
