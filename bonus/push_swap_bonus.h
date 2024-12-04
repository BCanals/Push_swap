/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 23:40:54 by bizcru            #+#    #+#             */
/*   Updated: 2024/12/04 16:47:25 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "../libft/libft.h"

t_node	*data_loader(int argc, char **argv);
t_node	*load_b(t_node **stack_a);
t_node	*initial_data_load(int *data);
char	**get_orders();
void	do_swap(t_node **stack);
void	do_r_rotate(t_node **stack);
void	do_rotate(t_node **stack);
void	do_push(t_node **stack_to, t_node **stack_from);
int		is_sorted(t_node *stack);

#endif
