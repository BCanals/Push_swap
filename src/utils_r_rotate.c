/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_r_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:35:57 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/28 21:12:52 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_r_rotate(t_node **stack)
{
	t_node	*last;

	last = ft_lstlast(*stack);
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	last->prev->next = NULL;
	last->prev = NULL;
}

void	r_rotate_one(t_node **stack, char c)
{
	do_r_rotate(stack);
	ft_printf("rr%c\n", c);
}

void	r_rotate_one_m(t_node **stack, char c, int i)
{
	while (i-- > 0)
		r_rotate_one (stack, c);
}

void	r_rotate_two(t_node **stack_a, t_node **stack_b)
{
	do_r_rotate(stack_a);
	do_r_rotate(stack_b);
	ft_printf("rrr\n");
}

void	r_rotate_two_m(t_node **stack_a, t_node **stack_b, int i)
{
	while (i-- > 0)
		r_rotate_two(stack_a, stack_b);
}
