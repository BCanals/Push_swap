/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:40:54 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/21 22:36:31 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

t_node	*data_loader(int argc, char **argv);
t_node	*initial_data_load(int *data);
void	swipe_one(t_node **stack, char c);
void	swipe_two(t_node **stack_a, t_node stack_b);
void	do_push(t_node **stack_to, t_node **stack_from, char c);
