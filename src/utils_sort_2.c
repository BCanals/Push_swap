/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:24:46 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/28 20:43:29 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sorts the stacks in order to prepare it for the push.
/*
static void	to_top_two(t_node **stk_a, t_node **stk_b, t_node *tgt, t_node *pair)
{
	if (max(tgt->r_len, pair->r_len) <= max(tgt->rr_len, pair->rr_len))
	{
		rotate_two_m(stk_a, stk_b, min(tgt->r_len, pair->r_len));
		if (tgt->r_len >= pair->r_len)
			rotate_one_m(stk_a, 'a', tgt->r_len - pair->r_len);
		else
			rotate_one_m(stk_b, 'b', pair->r_len - tgt->r_len);
	}
	else
	{
		r_rotate_two_m(stk_a, stk_b, min(tgt->rr_len, pair->rr_len));
		if (tgt->rr_len >= pair->rr_len)
			r_rotate_one_m(stk_a, 'a', tgt->rr_len - pair->rr_len);
		else
			r_rotate_one_m(stk_b, 'b', pair->rr_len - tgt->rr_len);
	}	
}*/

t_node	*get_pair(t_node *target, t_node *stack)
{
	// bucle per trobar el següent element de la llista
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


//unsigned int	path_len(t_node *target, t_node *pair)
//{
	// obté el camí més curt entre un element i la destinació
//}

//void	sort_one(t_node **stack_a, t_node **stack_b)
//{
	// min_path_len = 0;
	// pair = *t_node;
	// actualitzar r_len i rr_len (funció)
	// comprovem si el path_len és superior a min_path_len (funció)
	// si és el cas, mirem on va (funció)
	// comprovem si el path_len final es més curt que el min_path_len (funció)
	// si es el cas, actualitzem min_path_len, target_a i target_b; (
	// acabada la iteració, fem el canvi; (funció)

//}


void	update_r_lens(t_node *stack)
{
	t_node *last = ft_lstlast(stack);
	int		i;

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
