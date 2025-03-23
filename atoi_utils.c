/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kozcan <kozcan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:52:04 by kozcan            #+#    #+#             */
/*   Updated: 2025/03/21 16:52:11 by kozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_validate_char(const char *num_str, char **split_args)
{
	if (!ft_isdigit(*num_str) || ft_strlen(num_str) > 12)
		ps_cleanup_and_error(split_args);
}

int	ps_atoi_extended(const char *num_str, char **split_args)
{
	long long	accum;
	int			sign;

	accum = 0;
	sign = 1;
	while (*num_str == ' ' || *num_str == '\t' || *num_str == '\n'
		|| *num_str == '\f' || *num_str == '\v' || *num_str == '\r')
		num_str++;
	if (*num_str == '-' && *(num_str + 1) != '\0')
	{
		sign = -1;
		num_str++;
	}
	else if (*num_str == '+' && *(num_str + 1) != '\0')
		num_str++;
	while (*num_str)
	{
		ps_validate_char(num_str, split_args);
		accum = accum * 10 + (*num_str - '0');
		num_str++;
	}
	if ((sign * accum) > 2147483647 || (sign * accum) < -2147483648)
		ps_cleanup_and_error(split_args);
	return (sign * accum);
}

void	ps_cleanup_and_error(char **split_args)
{
	ps_free_string_array(split_args);
	ps_exit_error();
}
