/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:12:23 by bizcru            #+#    #+#             */
/*   Updated: 2024/12/14 01:57:00 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

// updates the fields r_len and rr_len from all the nodes in a stack.

void	update_r_lens(t_node *stack)
{
	t_node	*last;
	int		i;

	last = ft_lstlast(stack);
	i = 0;
	while (stack)
	{
		stack->r_len = i;
		i++;
		stack = stack->next;
	}
	i = 1;
	while (last)
	{
		last->rr_len = i;
		i++;
		last = last->prev;
	}
}

// Gets the place before which the target goes in the new stack
// This should be on utils_sort_1.c but you know, norminette :)

t_node	*get_pair(t_node *target, t_node *stack)
{
	t_node	*cand;
	t_node	*temp;

	temp = stack;
	cand = stack;
	temp = stack->next;
	while (temp)
	{
		if ((cand->data < target->data && temp->data > cand->data) \
			|| (temp->data < cand->data && temp->data > target->data))
			cand = temp;
		temp = temp->next;
	}
	if (cand->data < target->data)
		return (get_min(stack));
	return (cand);
}
