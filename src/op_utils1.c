/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:27:31 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/21 23:04:48 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	do_swipe(t_node **stack)
{
	t_node	*second;

	if (!*stack || !((**stack)->next))
		return ;
	second = (**stack)->next;
	(**stack)->next = (*second)->next;
	(*second)->next = *stack;
	*stack = next;
}

void	swipe_one(t_node **stack, char c)
{
	do_swipe(stack);
	ft_printf("s%c\n", c);
}

void	swipe_two(t_node **stack_a, t_node **stack_b)
{
	do_swipe(stack_a);
	do_swipe(stack_b);
	ft_printf("ss\n");
}

void	do_push(t_node **stack_to, t_node **stack_from, char c)
{
	t_node	*second;

	second = (**stack_from)->next;
	(**stack_from)->next = *stack_to;
	*stack_to = *stack_from;
	*stack_from = second;
	ft_printf("p%c\n", c);
}
