/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kozcan <kozcan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:13:06 by kozcan            #+#    #+#             */
/*   Updated: 2025/03/21 17:20:51 by kozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int		ps_atoi_extended(const char *str, char **strhead);
void	ps_cleanup_and_error(char **strhead);
void	ps_exit_error(void);
int		*ps_init_stack(int ac, char **av);
void	ps_free_string_array(char **tokens);
int		ps_parse_count(int ac, char **av, int idx, int j);
int		*ps_fill_stack(int ac, char **av, int *stack_a, int elem_count);
void	ps_check_duplicates(int *stack_a);
int		ps_is_sorted(int *stack_a);
int		ps_calc_b(int *stack_x, int num);
int		ps_find_index(int *stack_x, int num);
int		ps_local_cost(int *stack_x, int idx);
void	ps_future_flow(int *stack_a, int *stack_b, int min_idx);
void	ps_turn_stack(int *stack_x, int idx, int flag_stack);
int		ps_calc_pos(int *stack_a, int num);
void	ps_rt_and_pa(int *stack_a, int *stack_b, int num_moves, int min_idx);
int		ps_calc_final_cost(int val_a, int val_b);
void	ps_perfect_rotate(int *stack_x, int moves, int stack_flag);
void	ps_calc_move(int *stack_a, int *stack_b, int min_idx);
int		ps_min_cost_index(int *stack_a, int *stack_b, int min_idx);
void	ps_push_b(int *stack_a, int *stack_b, int min_idx);
void	ps_push_a(int *stack_a, int *stack_b, int min_idx);
void	ps_rotate_x(int *stack_x, int times, int stack_flag);
void	ps_reverse_rotate_x(int *stack_x, int times, int stack_flag);
void	ps_swap_a(int *stack_a);
void	ps_three_sort(int *stack_x, int stack_flag);
void	ps_rrr_maker(int *stack_x, int count);
void	ps_rr_maker(int *stack_x, int count);
void	ps_rotate_both(int *stack_a, int *stack_b, int a, int b);
void	ps_reverse_rotate_both(int *stack_a, int *stack_b, int a, int b);
void	ps_minmax_bounds(int *stack_a, int min_idx);
void	ps_rotate_and_pb(int *stack_a, int *stack_b, int moves, int min_idx);
void	ps_pre_sort(int *stack_a, int *stack_b, int min_idx);
void	ps_sort_stack(int *stack_a);

#endif
