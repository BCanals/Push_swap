/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:40:54 by bizcru            #+#    #+#             */
/*   Updated: 2024/12/04 19:37:49 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

t_node	*data_loader(int argc, char **argv);
int		sort_serf(t_node **stack_a, t_node **stack_b);
t_node	*initial_data_load(int *data);
int		is_sorted(t_node *stack);
void	swap_two(t_node **stack_a, t_node **stack_b);
void	rotate_two(t_node **stack_a, t_node **stack_b);
void	r_rotate_two(t_node **stack_a, t_node **stack_b);
void	do_swap(t_node **stack);
void	do_r_rotate(t_node **stack);
void	do_rotate(t_node **stack);
void	do_push(t_node **stack_to, t_node **stack_from);

#endif
