/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:40:54 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/28 11:45:19 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "../libft/libft.h"

//to-do: afegir t_node->pos que representi la position dins del conjunt d'elements
// per tal de facilitar si ja hem trobat el següent element.

t_node	*data_loader(int argc, char **argv);
t_node	*load_b(t_node **stack_a);
t_node	*initial_data_load(int *data);
void	swap_one(t_node **stack, char c);
void	swap_two(t_node **stack_a, t_node **stack_b);
void	do_push(t_node **stack_to, t_node **stack_from, char c);
void	rotate_one(t_node **stack, char c);
void	rotate_two(t_node **stack_a, t_node **stack_b);
void	r_rotate_one(t_node **stack, char c);
void	r_rotate_two(t_node **stack_a, t_node **stack_b);
int		is_sorted(t_node *stack);
void	sort_master(t_node **stack_a);
void	sort_three(t_node **stack);
t_node	*get_pair(t_node *target, t_node *pair_stack);
void	update_r_lens(t_node *stack);
void	do_sort(t_node **stk_f, t_node **stk_t, t_node *tgt, t_node *pair);


void	print_lst(int data);
#endif
