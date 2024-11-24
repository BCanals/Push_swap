/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:40:54 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/24 23:53:14 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"

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
