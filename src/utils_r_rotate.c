/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_r_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:35:57 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/27 18:28:46 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void do_r_rotate(t_node **stack)
{
	t_node *last;

	last = ft_lstlast(*stack);
	last->next = *stack;
	(*stack)->next = last;
	*stack = last;
	last->prev->next = NULL;
	last->prev = NULL;
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
