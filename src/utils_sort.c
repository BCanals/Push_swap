/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:54:55 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/28 11:45:17 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
//unsigned int	pre_path_len(t_node)
{
	// fer el mínim r_len rr_len;
}

//unsigned int	path_len(t_node *target, t_node *pair)
{
	// obté el camí més curt entre un element i la destinació
}

//void	sort_one(t_node **stack_a, t_node **stack_b)
{
	// min_path_len = 0;
	// pair = *t_node;
	// actualitzar r_len i rr_len (funció)
	// comprovem si el path_len és superior a min_path_len (funció)
	// si és el cas, mirem on va (funció)
	// comprovem si el path_len final es més curt que el min_path_len (funció)
	// si es el cas, actualitzem min_path_len, target_a i target_b; (
	// acabada la iteració, fem el canvi; (funció)

}*/

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
	// fer un bucle amb els ddnexts i els prevs amb un índex;
	// fer un bucle amb els ddnexts i els prevs amb un índex;
}


// sorts the stacks in order to prepare it for the push.

void	do_sort(t_node **stk_f, t_node **stk_t, t_node *tgt, t_node *pair)
{
	
}

t_node	*get_pair(t_node *target, t_node *stack)
{
	// bucle per trobar el següent element de la llista
	t_node	*cand;

	cand = stack;
	stack = stack->next;
	while (*stack)
	{
		if (stack->data < cand->data && stack->data > taget->data)
			cand = stack;
		stack = stack->next;
	}
	return (cand);
}

void	return_data(t_node **stack_a; t_node **stack_b);
{
	t_node	*pair;

	while (*stack_b)
	{
		pair = get_pair(*stack_b, *stack_a);
		update_r_lens(*stack_a);
		(*stack_b)->r_len = 0;
		(*stack_b)->rr_len = 0;
		do_sort(stack_b, stack_a, *stack_b, pair);
		do_push(stack_a, stack_b, 'a');
	}
}

void	sort_three(t_node **stack)
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
		ft_printf("sa\n");
	if (size < 3)
		return ;
	stack_b = NULL;
	if (size > 3)
		stack_b = load_b(stack_a);
	// mentre la stack_a té més de 3 elements, n'ordenem un
	sort_three(stack_a);
	if (stack_b)
		return_data(stack_a, stack_b);
	return ;
}
