/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:24:46 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/28 22:59:46 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sorts the stacks in order to prepare it for the push.

static void	top_comb(t_node **s_a, t_node **s_b, t_node *tgt, t_node *pair)
{
	if (max(tgt->r_len, pair->r_len) <= max(tgt->rr_len, pair->rr_len))
	{
		rotate_two_m(s_a, s_b, min(tgt->r_len, pair->r_len));
		if (tgt->r_len >= pair->r_len)
			rotate_one_m(s_a, 'a', tgt->r_len - pair->r_len);
		else
			rotate_one_m(s_b, 'b', pair->r_len - tgt->r_len);
	}
	else
	{
		r_rotate_two_m(s_a, s_b, min(tgt->rr_len, pair->rr_len));
		if (tgt->rr_len >= pair->rr_len)
			r_rotate_one_m(s_a, 'a', tgt->rr_len - pair->rr_len);
		else
			r_rotate_one_m(s_b, 'b', pair->rr_len - tgt->rr_len);
	}
}

// Gets the place before which the target goes in the new stack

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

// gets the minimum number of operations to sort the target next to pair.

static int	path_len(t_node *tgt, t_node *pair)
{
	int	a;
	int	b;

	a = min(tgt->r_len + pair->rr_len, tgt->rr_len + pair->r_len);
	b = min(max(tgt->r_len, pair->r_len), max(tgt->rr_len, pair->rr_len));
	return (min(a, b));
}

// Helper function for sort_one to enter the loop only the interesting nodes
/*
static int iter_ok(t_node **current, int min_path, t_node **pair, int *path_len)
{
	if (!*current)
		return (0);
	while (min((*current)->r_len, (*current)->rr_len) >= min_path)
	{
		*current = (*current)->next;
		if (!*current)
			return (0);
	}
	return (1);
}*/

// Manages the necessary steps to move one element from stack_a to stack_b

void	sort_one(t_node **stack_a, t_node **stack_b)
{
	t_node	*current;
	t_node	*pair;
	int		min_path;
	t_node	*tgt_sort;
	t_node	*pair_sort;

	min_path = ft_lstsize(*stack_a) / 2 + 1;
	current = *stack_a;
	while (current)
	{
		pair = get_pair(current, *stack_b);
		if (path_len(current, pair) < min_path)
		{
			min_path = path_len(current, pair);
			tgt_sort = current;
			pair_sort = pair;
		}
		current = current->next;
	}
	to_top_two(stack_a, stack_b, tgt_sort, pair_sort);
	do_push(stack_b, stack_a, 'b');
}
