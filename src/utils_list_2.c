/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:12:23 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/28 21:45:08 by bizcru           ###   ########.fr       */
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

