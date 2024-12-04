/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ops_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:35:57 by bizcru            #+#    #+#             */
/*   Updated: 2024/12/04 19:48:16 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	do_swap(t_node **stack)
{
	t_node	*second;

	if (!(*stack)->next->next)
	{
		second = *stack;
		*stack = (*stack)->next;
		(*stack)->next = second;
		(*stack)->prev = NULL;
		second->next = NULL;
		second->prev = *stack;
		return ;
	}
	second = (*stack)->next;
	second->prev = NULL;
	(*stack)->next = second->next;
	(*stack)->prev = second;
	second->next->prev = *stack;
	second->next = *stack;
	*stack = second;
}

void	do_r_rotate(t_node **stack)
{
	t_node	*last;

	if (!(*stack)->next->next)
		return (do_swap(stack));
	last = ft_lstlast(*stack);
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	last->prev->next = NULL;
	last->prev = NULL;
}

void	do_rotate(t_node **stack)
{
	t_node	*last;

	if (!(*stack)->next->next)
		return (do_swap(stack));
	(*stack)->next->prev = NULL;
	last = ft_lstlast(*stack);
	last->next = *stack;
	(*stack)->prev = last;
	last = *stack;
	*stack = (*stack)->next;
	last->next = NULL;
}

/*
	Does the first push to b, when there's no stack_b pointer yet,
	and returns (for the first time) a stack_b pointer.
*/

static t_node	*load_b(t_node **stack_a)
{
	t_node	*stack_b;

	stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	stack_b->next = NULL;
	return (stack_b);
}

void	do_push(t_node **stack_to, t_node **stack_from)
{
	t_node	*second;
	
	if (!*stack_to)
	{
		*stack_to = load_b(stack_from);
		return ;
	}
	second = NULL;
	if ((*stack_from)->next)
	{
		second = (*stack_from)->next;
		second->prev = NULL;
	}
	(*stack_from)->next = *stack_to;
	(*stack_to)->prev = *stack_from;
	*stack_to = *stack_from;
	*stack_from = second;
}
