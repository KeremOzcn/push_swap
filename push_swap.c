/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kozcan <kozcan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:56:45 by kozcan            #+#    #+#             */
/*   Updated: 2025/03/21 16:56:55 by kozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = ps_init_stack(argc, argv);
	ps_check_duplicates(stack_a);
	if (ps_is_sorted(stack_a))
	{
		free(stack_a);
		return (0);
	}
	if (stack_a[0] == 2)
	{
		ps_swap_a(stack_a);
		free(stack_a);
	}
	else
		ps_sort_stack(stack_a);
	return (0);
}
