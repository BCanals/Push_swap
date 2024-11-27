/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:27:31 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/27 18:44:20 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_swap(t_node **stack)
{
	t_node	*second;

	if (!*stack || !((*stack)->next))
		return ;
	second = (*stack)->next;
	second->prev = NULL;
	(*stack)->next = second->next;
	(*stack)->prev = second;
	second->next->prev = *stack;
	second->next = *stack;
	*stack = second;
}

void	swap_one(t_node **stack, char c)
{
	do_swap(stack);
	ft_printf("s%c\n", c);
}

void	swap_two(t_node **stack_a, t_node **stack_b)
{
	do_swap(stack_a);
	do_swap(stack_b);
	ft_printf("ss\n");
}

void	do_push(t_node **stack_to, t_node **stack_from, char c)
{
	t_node	*second;

	second = (*stack_from)->next;
	(*stack_from)->next = *stack_to;
	*stack_to = *stack_from;
	*stack_from = second;
	ft_printf("p%c\n", c);
}
