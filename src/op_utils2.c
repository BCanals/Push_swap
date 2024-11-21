/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:35:57 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/21 23:26:11 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	do_rotate(t_node **stack)
{
	t_node *last;

	last = ft_lstlast(*stack);
	(*last)->next = *stack;
	last = *stack;
	*stack = (*last)->next;
	(*last)->next = NULL;
}

void	rotate_one ();
void	rotate_two ();

