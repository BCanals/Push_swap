/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:54:55 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/28 20:44:00 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotates the list until the "top" node is the first position.

static void	to_top_one(t_node **stack, t_node *top)
{
	if (top->r_len <= top->rr_len)
		rotate_one_m(stack, 'a', top->r_len);
	else
		r_rotate_one_m(stack, 'a', top->rr_len);
}

// Manages the bringing back of data from stack_b to stack_a.

static void	return_data(t_node **stack_a, t_node **stack_b)
{
	t_node	*pair;

	while (*stack_b)
	{
		pair = get_pair(*stack_b, *stack_a);
		update_r_lens(*stack_a);
		to_top_one(stack_a, pair);
		do_push(stack_a, stack_b, 'a');
	}
	pair = get_min(*stack_a);
	update_r_lens(*stack_a);
	to_top_one(stack_a, pair);
}

// Makes sure that the 3-elements stac (a) is in the correct order.
// It does'nt necessary means it will be sorted.

static void	sort_three(t_node **stack)
{
	if (get_min(*stack)->next == get_max(*stack))
		swap_one(stack, 'a');
	else if (get_min(*stack)->next == NULL && get_max(*stack)->prev == NULL)
		swap_one(stack, 'a');
}

// Makes sure that the 3-elements stack is in order and sorted.

static void	full_sort_three(t_node **stack)
{
	t_node	*first;
	t_node	*mid;
	t_node	*last;

	while (!is_sorted(*stack))
	{
		first = *stack;
		mid = first->next;
		last = mid->next;
		if (mid->data > first->data && mid->data > last->data)
			r_rotate_one(stack, 'a');
		else if (last->data > mid->data && last->data < first->data)
			rotate_one(stack, 'a');
		else
			swap_one(stack, 'a');
	}
}

void	sort_master(t_node **stack_a)
{
	t_node	*stack_b;
	int		size;

	size = ft_lstsize(*stack_a);
	if (size == 2 && !is_sorted(*stack_a))
		swap_one(stack_a, 'a');
	if (size == 3)
		full_sort_three(stack_a);
	if (is_sorted(*stack_a))
		return ;
	stack_b = load_b(stack_a);
	//while (ft_lstsize(*stack_a) > 3)
	//	sort_one(stack_a, &stack_b);
	sort_three(stack_a);
	if (stack_b)
		return_data(stack_a, &stack_b);
	return ;
}
