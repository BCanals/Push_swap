/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:35:57 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/28 09:41:38 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rotate(t_node **stack)
{
	t_node *last;

	(*stack)->next->prev = NULL;
	last = ft_lstlast(*stack);
	last->next = *stack;
	(*stack)->prev = last;
	last = *stack;
	*stack = (*stack)->next;
	last->next = NULL;
}

void	rotate_one (t_node **stack, char c)
{
	do_rotate(stack);
	ft_printf("r%c\n", c);

}

void	rotate_two (t_node **stack_a, t_node **stack_b)
{
	do_rotate(stack_a);
	do_rotate(stack_b);
	ft_printf("rr\n");
}
