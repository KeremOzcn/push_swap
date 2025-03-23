/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kozcan <kozcan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:53:57 by kozcan            #+#    #+#             */
/*   Updated: 2025/03/21 16:54:02 by kozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ps_check_duplicates(int *stack_a)
{
	int	idx;
	int	cmp_idx;

	cmp_idx = 1;
	while (cmp_idx < stack_a[0])
	{
		idx = cmp_idx + 1;
		while (idx < stack_a[0] + 1)
		{
			if (stack_a[cmp_idx] == stack_a[idx])
			{
				free(stack_a);
				ps_exit_error();
			}
			idx++;
		}
		cmp_idx++;
	}
}

int	ps_is_sorted(int *stack_a)
{
	int	idx;

	idx = 1;
	while (idx < stack_a[0])
	{
		if (stack_a[idx] < stack_a[idx + 1])
			return (0);
		idx++;
	}
	return (1);
}
