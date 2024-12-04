/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_misc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:18:14 by bizcru            #+#    #+#             */
/*   Updated: 2024/12/04 19:20:28 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
   Takes an array of integer where array[0] is the number of elements to copy.
   Creates and returns the head of the stack_a with the given data.
*/

t_node	*initial_data_load(int *data)
{
	t_node	*stack_a;
	t_node	*new;
	int		i;

	stack_a = ft_lstnew(data + 1);
	if (!stack_a)
	{
		free(data);
		return (NULL);
	}
	i = 2;
	while (i <= data[0])
	{
		new = ft_lstnew(data + i++);
		if (!new)
		{
			free(data);
			ft_lstclear(&stack_a);
			return (NULL);
		}
		ft_lstadd_back(&stack_a, new);
	}
	return (stack_a);
}

/*
   Returns 1 if the stack is sorted and 0 otherwise.
*/

int	is_sorted(t_node *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	rotate_two(t_node **stack_a, t_node **stack_b)
{
	do_rotate(stack_a);
	do_rotate(stack_b);
}

void	r_rotate_two(t_node **stack_a, t_node **stack_b)
{
	do_r_rotate(stack_a);
	do_r_rotate(stack_b);
}

void	swap_two(t_node **stack_a, t_node **stack_b)
{
	do_swap(stack_a);
	do_swap(stack_b);
}
