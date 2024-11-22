/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_r_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:35:57 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/22 20:32:23 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_r_rotate(t_node **stack)
{
	t_node *not_last;

	not_last = ft_lstlast_prev(*stack);
	not_last->next->next = *stack;
	*stack = not_last->next;
	not_last->next = NULL;
}

void	r_rotate_one (t_node **stack, char c)
{
	do_r_rotate(stack);
	ft_printf("rr%c\n", c);

}
void	r_rotate_two (t_node **stack_a, t_node **stack_b)
{
	do_r_rotate(stack_a);
	do_r_rotate(stack_b);
	ft_printf("rrr\n");
}
