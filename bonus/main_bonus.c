/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:50:33 by bizcru            #+#    #+#             */
/*   Updated: 2024/12/14 01:09:21 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	stack_a = data_loader(argc, argv);
	if (!stack_a)
		return (ft_putstr_fd("Error\n", 2));
	if (!sort_serf(&stack_a, &stack_b))
		return (ft_putstr_fd("Error\n", 2));
	if (!stack_b && is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(&stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
