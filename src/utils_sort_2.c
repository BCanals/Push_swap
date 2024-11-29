/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:24:46 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/29 20:14:40 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sorts the stacks in order and do the push, assuming r_r or rr_rr.

static void	top_same(t_node **s_a, t_node **s_b, t_node *tgt, t_node *pair)
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
	do_push(s_b, s_a, 'b');
}

// sorts the stacks in order and do the push, assuming r_rr or rr_r.

static void	top_diff(t_node **s_a, t_node **s_b, t_node *tgt, t_node *pair)
{
	if (tgt->rr_len + pair->r_len <= tgt->r_len + pair->rr_len)
	{
		r_rotate_one_m(s_a, 'a', tgt->rr_len);
		rotate_one_m(s_b, 'b', pair->r_len);
	}
	else
	{
		rotate_one_m(s_a, 'a', tgt->r_len);
		r_rotate_one_m(s_b, 'b', pair->rr_len);
	}
	do_push(s_b, s_a, 'b');
}

// gets the minimum number of operations to sort the target next to pair.

static int	path_len_type(t_node *tgt, t_node *pair, int path)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = max(tgt->r_len, pair->r_len);
	b = max(tgt->rr_len, pair->rr_len);
	c = tgt->rr_len + pair->r_len;
	d = tgt->r_len + pair->rr_len;
	if (path)
	{
		if (min(a, b) <= min (c, d))
			return (1);
		else
			return (0);
	}
	return (min(min(a, b), min(c, d)));
}

// Gets the place after which the target goes in the new stack

static t_node	*get_r_pair(t_node *target, t_node *stack)
{
	t_node	*cand;
	t_node	*temp;

	temp = stack;
	cand = stack;
	temp = stack->next;
	while (temp)
	{
		if ((cand->data > target->data && temp->data < cand->data) \
			|| (temp->data > cand->data && temp->data < target->data))
			cand = temp;
		temp = temp->next;
	}
	return (cand);
}

// Manages the necessary steps to move one element from stack_a to stack_b

void	sort_one(t_node **stack_a, t_node **stack_b)
{
	t_node	*current;
	t_node	*pair;
	int		min_path;
	t_node	*tgt_sort;
	t_node	*pair_sort;

	min_path = 100000;
	current = *stack_a;
	while (current)
	{
		pair = get_r_pair(current, *stack_b);
		if (path_len_type(current, pair, 0) < min_path)
		{
			min_path = path_len_type(current, pair, 0);
			tgt_sort = current;
			pair_sort = pair;
		}
		current = current->next;
	}
	if (path_len_type(tgt_sort, pair_sort, 1))
		top_same(stack_a, stack_b, tgt_sort, pair_sort);
	else
		top_diff(stack_a, stack_b, tgt_sort, pair_sort);
}
