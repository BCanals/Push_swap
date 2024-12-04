/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:50:33 by bizcru            #+#    #+#             */
/*   Updated: 2024/12/04 14:40:39 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	char	**orders;

	if (argc == 1)
		return (0);
	*stack_a = data_loader(argc, argv);
	if (!*stack_a)
		return (ft_putstr_fd("Error\n", 2));
	orders = get_orders();
	if (!orders)
		return (ft_putstr_cd("Error\n", 2));
	sort_serf(stack_a, orders);
	if (is_sorted(*stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(stack_a);
	return (0);
}
