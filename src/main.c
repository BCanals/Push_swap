/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:50:33 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/29 20:09:29 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

void	print_lst(int data)
{
	ft_printf("%i\n", data);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;

	if (argc == 1)
		return (0);
	stack_a = data_loader(argc, argv);
	if (!stack_a)
		return (ft_putstr_fd("Error\n", 2));
	sort_master(&stack_a);
	ft_lstclear(&stack_a);
	return (0);
}
